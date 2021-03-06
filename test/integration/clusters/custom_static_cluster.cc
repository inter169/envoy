#include "custom_static_cluster.h"

namespace Envoy {

// ClusterImplBase
void CustomStaticCluster::startPreInit() {
  printf("startPreInit");
  Upstream::HostSharedPtr host = makeHost();
  Upstream::HostVector hosts{host};
  auto hosts_ptr = std::make_shared<Upstream::HostVector>(hosts);

  this->priority_set_.updateHosts(
      priority_,
      Upstream::HostSetImpl::partitionHosts(hosts_ptr, Upstream::HostsPerLocalityImpl::empty()), {},
      hosts, {}, absl::nullopt);

  onPreInitComplete();
}

inline Upstream::HostSharedPtr CustomStaticCluster::makeHost() {
  Network::Address::InstanceConstSharedPtr address =
      Network::Utility::parseInternetAddress(address_, port_, false);
  return Upstream::HostSharedPtr{new Upstream::HostImpl(
      this->info(), "", address, this->info()->metadata(), 1,
      envoy::api::v2::core::Locality::default_instance(),
      envoy::api::v2::endpoint::Endpoint::HealthCheckConfig::default_instance(), priority_,
      envoy::api::v2::core::HealthStatus::UNKNOWN)};
}

REGISTER_FACTORY(CustomStaticClusterFactory, Upstream::ClusterFactory);

} // namespace Envoy