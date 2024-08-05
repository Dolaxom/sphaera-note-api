#include "client.h"

AuthorizationClient::AuthorizationClient(std::shared_ptr<Channel> channel)
  : stub_(AuthorizationService::NewStub(channel)) {}

SignUpResponse AuthorizationClient::SignUp(const std::string& email, const std::string& password, const std::string& name) {
  SignUpRequest request;
  request.set_email(email);
  request.set_password(password);
  request.set_name(name);

  SignUpResponse response;
  ClientContext context;

  Status status = stub_->SignUp(&context, request, &response);

  if (status.ok()) {
    return response;
  } else {
    std::cerr << "RPC failed: " << status.error_message() << std::endl;
    response.set_success(false);
    response.set_message("RPC call failed");
    return response;
  }
}

