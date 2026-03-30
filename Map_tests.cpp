#include "Map.hpp"
#include "unit_test_framework.hpp"


TEST(test_stub) {
    // Add your tests here
    ASSERT_TRUE(true);
}

TEST(test_custom_comparator) {
    // Map with reverse order comparator
    Map<int, std::string, std::greater<int>> custom_map;
    custom_map.insert({5, "five"});
    custom_map.insert({10, "ten"});
    custom_map.insert({1, "one"});

    std::vector<int> expected_keys = {10, 5, 1};
    std::vector<int> actual_keys;

    for (auto &pair : custom_map) {
        actual_keys.push_back(pair.first);
    }

    ASSERT_EQUAL(expected_keys, actual_keys); // Ensure reverse order is respected
}

TEST(test_overwrite_keys) {
    Map<std::string, int> map;
    map.insert({"key1", 1});
    map.insert({"key2", 2});

    // Overwrite value for "key1"
    map["key1"] = 10;

    ASSERT_EQUAL(map["key1"], 10); // Verify updated value
    ASSERT_EQUAL(map["key2"], 2);  // Verify unaffected value
}

TEST(test_iterator_modification) {
    Map<std::string, int> map;
    map.insert({"key1", 1});
    map.insert({"key2", 2});
    map.insert({"key3", 3});

    // Attempt to modify map during iteration
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it->first == "key2") {
            map["key4"] = 4; // Add new element
        }
    }

    ASSERT_EQUAL(map.size(), 4); // Ensure map has the new element
    ASSERT_TRUE(map.find("key4") != map.end());
}



TEST_MAIN()
