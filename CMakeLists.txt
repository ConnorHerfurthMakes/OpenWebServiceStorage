cmake_minimum_required(VERSION 3.14)

project(openwebstorage)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Google Tests (shamelessly taken from https://google.github.io/googletest/quickstart-cmake.html)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
## End Google Tests

add_executable(openwebstorage main.cpp "blob/Blob.h" "blob/communications/PutResponse.h" "blob/communications/PutRequest.h" "blob/types/ObjectKey.h" "blob/types/ObjectKey.cpp" "blob/communications/PutRequest.cpp" "blob/communications/PutResponse.cpp" "blob/communications/GetRequest.h" "blob/communications/GetRequest.cpp" "blob/communications/GetResponse.h" "blob/communications/GetResponse.cpp"  "blob/communications/DeleteRequest.h" "blob/communications/DeleteRequest.cpp" "blob/communications/DeleteResponse.h" "blob/communications/DeleteResponse.cpp" "blob/communications/ListRequest.h" "blob/communications/ListRequest.cpp" "blob/communications/ListResponse.h" "blob/communications/ListResponse.cpp" "blob/Blob.cpp")

install(TARGETS openwebstorage RUNTIME DESTINATION bin)

enable_testing()

add_executable(
  blob_test
  "test/Blob_test.cc"
  "blob/Blob.h" "blob/communications/PutResponse.h" "blob/communications/PutRequest.h" "blob/types/ObjectKey.h" "blob/types/ObjectKey.cpp" "blob/communications/PutRequest.cpp" "blob/communications/PutResponse.cpp" "blob/communications/GetRequest.h" "blob/communications/GetRequest.cpp" "blob/communications/GetResponse.h" "blob/communications/GetResponse.cpp"  "blob/communications/DeleteRequest.h" "blob/communications/DeleteRequest.cpp" "blob/communications/DeleteResponse.h" "blob/communications/DeleteResponse.cpp" "blob/communications/ListRequest.h" "blob/communications/ListRequest.cpp" "blob/communications/ListResponse.h" "blob/communications/ListResponse.cpp" "blob/Blob.cpp"
)
target_link_libraries(
  blob_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(blob_test)