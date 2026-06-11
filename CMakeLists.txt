cmake_minimum_required(VERSION 3.10)

project(openwebstorage)

add_executable(openwebstorage main.cpp "blob/Blob.h" "blob/communications/PutResponse.h" "blob/communications/PutRequest.h" "blob/types/ObjectKey.h" "blob/types/ObjectKey.cpp" "blob/communications/PutRequest.cpp" "blob/communications/PutResponse.cpp" "blob/communications/GetRequest.h" "blob/communications/GetRequest.cpp" "blob/communications/GetResponse.h" "blob/communications/GetResponse.cpp"  "blob/communications/DeleteRequest.h" "blob/communications/DeleteRequest.cpp" "blob/communications/DeleteResponse.h" "blob/communications/DeleteResponse.cpp" "blob/communications/ListRequest.h" "blob/communications/ListRequest.cpp" "blob/communications/ListResponse.h" "blob/communications/ListResponse.cpp" "blob/Blob.cpp")

install(TARGETS openwebstorage RUNTIME DESTINATION bin)
