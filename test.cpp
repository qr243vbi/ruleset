#include "lib.pb.cc"
#include <fstream>

int main() {
    // Initialize the Protocol Buffers library
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // Create a new RuleSet instance
    RuleSet ruleset;

    // Open the binary file for reading
    std::ifstream input("rule-set/srslist", std::ios::in | std::ios::binary);
    if (!input) {
        std::cerr << "Failed to open file." << std::endl;
        return -1;
    }

    // Read the serialized data from the file
    if (!ruleset.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse RuleSet." << std::endl;
        return -1;
    }

    // Close the file
    input.close();

    // Print the deserialized items
    for (const auto& pair : ruleset.items()) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Optional: Shutdown the Protocol Buffers library
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
