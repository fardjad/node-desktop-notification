#include <node.h>
#include <v8.h>
#include <notification.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  
  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsString()) {
    ThrowException(Exception::TypeError(String::New("Wrong arguments")));
    return scope.Close(Undefined());
  }

  String::Utf8Value param1(args[0]->ToString());
  Notification::show(*param1);

  return scope.Close(True());
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("show"),
      FunctionTemplate::New(Method)->GetFunction());
}

NODE_MODULE(notification, init)
