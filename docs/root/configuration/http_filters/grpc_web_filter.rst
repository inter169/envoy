.. _config_http_filters_grpc_web:

gRPC-Web
========

* gRPC :ref:`architecture overview <arch_overview_grpc>`
* :ref:`v2 API reference <envoy_api_field_config.filter.network.http_connection_manager.v2.HttpFilter.name>`
* This filter should be configured with the name *envoy.grpc_web*.

This is a filter which enables the bridging of a gRPC-Web client to a compliant gRPC server by
following https://github.com/grpc/grpc/blob/master/doc/PROTOCOL-WEB.md.
