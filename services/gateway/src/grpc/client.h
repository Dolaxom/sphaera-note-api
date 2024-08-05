#pragma once

#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>

#include "authorization.grpc.pb.h"

using authorization::AuthorizationService;
using authorization::SignUpRequest;
using authorization::SignUpResponse;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;


class AuthorizationClient {
public:
  explicit AuthorizationClient(std::shared_ptr<Channel> channel);

  SignUpResponse SignUp(const std::string& email, const std::string& password, const std::string& name);

private:
  std::unique_ptr<AuthorizationService::Stub> stub_;
};


