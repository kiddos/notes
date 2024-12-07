#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

int main(void) {
  mongocxx::instance instance{};

  try {
    mongocxx::uri uri("mongodb://mongoadmin:123456@localhost:27017");
    mongocxx::client client(uri);

    // Access the database and collection
    auto db = client["testdb"];
    auto collection = db["testcollection"];

    // Create a BSON document
    bsoncxx::builder::stream::document document{};
    document << "name" << "Alice" << "age" << 30 << "city" << "Wonderland";

    // Insert the document into the collection
    auto result = collection.insert_one(document.view());
    if (result) {
      std::cout << "Inserted document ID: "
                << result->inserted_id().get_oid().value.to_string()
                << std::endl;
    }

    // Query the document
    auto cursor = collection.find({});
    for (auto&& doc : cursor) {
      std::cout << "Document: " << bsoncxx::to_json(doc) << std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
