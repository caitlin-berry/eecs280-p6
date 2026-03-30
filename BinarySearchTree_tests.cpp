#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"


// TEST(test_stub) {
//     // Add your tests here
//     ASSERT_TRUE(true);
// }

TEST(test_empty_tree) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.empty());
    ASSERT_EQUAL(bst.size(), 0);
    ASSERT_EQUAL(bst.height(), 0);
}

TEST(test_insert_and_find) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    ASSERT_TRUE(bst.find(10) != bst.end());
    ASSERT_TRUE(bst.find(5) != bst.end());
    ASSERT_TRUE(bst.find(20) != bst.end());
    ASSERT_TRUE(bst.find(15) == bst.end());
}

TEST(test_min_max_element) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(20);
    ASSERT_EQUAL(*bst.min_element(), 5);
    ASSERT_EQUAL(*bst.max_element(), 20);
}

TEST(test_single_node_tree) {
    BinarySearchTree<int> bst;
    bst.insert(42);
    ASSERT_FALSE(bst.empty());
    ASSERT_EQUAL(bst.size(), 1);
    ASSERT_EQUAL(bst.height(), 1);
    ASSERT_EQUAL(*bst.min_element(), 42);
    ASSERT_EQUAL(*bst.max_element(), 42);
}

TEST(test_traverse_inorder) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    std::ostringstream os;
    bst.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), "5 10 15 ");
}

TEST(test_traverse_preorder) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    std::ostringstream os;
    bst.traverse_preorder(os);
    ASSERT_EQUAL(os.str(), "10 5 15 ");
}

TEST(test_check_sorting_invariant) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    ASSERT_TRUE(bst.check_sorting_invariant());
}

TEST(test_min_greater_than) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(20);
    ASSERT_EQUAL(*bst.min_greater_than(10), 15);
    ASSERT_EQUAL(*bst.min_greater_than(5), 10);
    ASSERT_TRUE(bst.min_greater_than(20) == bst.end());
}

TEST(test_size_and_height) {
    BinarySearchTree<int> bst;
    ASSERT_EQUAL(bst.size(), 0);
    ASSERT_EQUAL(bst.height(), 0);
    bst.insert(10);
    ASSERT_EQUAL(bst.size(), 1);
    ASSERT_EQUAL(bst.height(), 1);
    bst.insert(5);
    ASSERT_EQUAL(bst.size(), 2);
    ASSERT_EQUAL(bst.height(), 2);
    bst.insert(15);
    ASSERT_EQUAL(bst.size(), 3);
    ASSERT_EQUAL(bst.height(), 2);
    bst.insert(1);
    ASSERT_EQUAL(bst.size(), 4);
    ASSERT_EQUAL(bst.height(), 3);
}

TEST(test_iterator) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    auto it = bst.begin();
    ASSERT_EQUAL(*it, 5);
    ++it;
    ASSERT_EQUAL(*it, 10);
    ++it;
    ASSERT_EQUAL(*it, 15);
    ++it;
    ASSERT_TRUE(it == bst.end());
}

TEST(test_copy_constructor) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    BinarySearchTree<int> bst_copy(bst);
    ASSERT_EQUAL(bst.size(), bst_copy.size());
    ASSERT_TRUE(bst_copy.find(10) != bst_copy.end());
    ASSERT_TRUE(bst_copy.find(5) != bst_copy.end());
    ASSERT_TRUE(bst_copy.find(15) != bst_copy.end());
    bst.insert(20);
    ASSERT_TRUE(bst.find(20) != bst.end());
    ASSERT_TRUE(bst_copy.find(20) == bst_copy.end());
}

TEST(test_assignment_operator) {
    BinarySearchTree<int> bst1;
    bst1.insert(10);
    bst1.insert(5);
    BinarySearchTree<int> bst2;
    bst2.insert(20);
    bst2.insert(15);
    bst1 = bst2; 
    ASSERT_EQUAL(bst1.size(), bst2.size());
    ASSERT_TRUE(bst1.find(20) != bst1.end());
    ASSERT_TRUE(bst1.find(15) != bst1.end());
    ASSERT_TRUE(bst1.find(10) == bst1.end());
}

TEST(test_destructor) {
    BinarySearchTree<int>* bst = new BinarySearchTree<int>();
    bst->insert(10);
    bst->insert(5);
    bst->insert(15);
    delete bst; 
}

TEST(test_min_greater_than_edge) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    ASSERT_TRUE(bst.min_greater_than(15) == bst.end()); 
    ASSERT_EQUAL(*bst.min_greater_than(5), 10);
}

TEST(test_iterator_empty_tree) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.begin() == bst.end());
}

TEST(test_imbalanced_tree_height) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3); 
    ASSERT_EQUAL(bst.height(), 3);
    BinarySearchTree<int> balanced_bst;
    balanced_bst.insert(2);
    balanced_bst.insert(1);
    balanced_bst.insert(3); 
    ASSERT_EQUAL(balanced_bst.height(), 2);
}

TEST(test_size_complex_tree) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(13);
    bst.insert(17);
    ASSERT_EQUAL(bst.size(), 7);
    ASSERT_EQUAL(bst.height(), 3);
}

TEST(test_postfix_iterator_increment) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    auto it = bst.begin();
    ASSERT_EQUAL(*it, 5);
    auto it_post = it++;
    ASSERT_EQUAL(*it_post, 5);
    ASSERT_EQUAL(*it, 10);
}

TEST(test_min_element_complex_tree) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(1);  
    bst.insert(7);
    bst.insert(15);
    bst.insert(12);
    bst.insert(20);
    ASSERT_EQUAL(*bst.min_element(), 1); 
}

TEST(test_min_element_single_node) {
    BinarySearchTree<int> bst;
    bst.insert(42);
    ASSERT_EQUAL(*bst.min_element(), 42); 
}

TEST(test_min_element_empty_tree) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.min_element() == bst.end()); 
}

TEST(test_max_element_right_skewed_tree) {
    BinarySearchTree<int> bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);  
    ASSERT_EQUAL(*bst.max_element(), 3);
}

TEST(test_max_element_complex_tree) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(1);
    bst.insert(7);
    bst.insert(15);
    bst.insert(12);
    bst.insert(20);  
    ASSERT_EQUAL(*bst.max_element(), 20); 
}

TEST(test_max_element_empty_tree) {
    BinarySearchTree<int> bst;
    ASSERT_TRUE(bst.max_element() == bst.end()); 
}

TEST(test_min_greater_than_multiple_candidates) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(12);
    bst.insert(20);
    ASSERT_EQUAL(*bst.min_greater_than(10), 12); 
    ASSERT_EQUAL(*bst.min_greater_than(5), 10); 
}

TEST(test_min_greater_than_no_greater) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    ASSERT_TRUE(bst.min_greater_than(15) == bst.end()); 
}

TEST(test_traverse_inorder_single_node) {
    BinarySearchTree<int> bst;
    bst.insert(42);
    std::ostringstream os;
    bst.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), "42 ");
}

TEST(test_traverse_inorder_complex_tree) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(1);
    bst.insert(7);
    bst.insert(15);
    bst.insert(12);
    bst.insert(20);
    std::ostringstream os;
    bst.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), "1 5 7 10 12 15 20 ");
}

TEST(test_insert_strict_order) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(9);  
    bst.insert(11); 
    ASSERT_EQUAL(*bst.min_element(), 9);
    ASSERT_EQUAL(*bst.max_element(), 11);
}

TEST(test_find_non_existent) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    ASSERT_TRUE(bst.find(8) == bst.end()); 
}

// Hint 1 for "BinarySearchTree Bug 12"
// BinarySearchTree::check_sorting_invariant() Bug #1

// Hint 2 for "BinarySearchTree Bug 12"
// BinarySearchTree::check_sorting_invariant() Bug #1 
// Ensure your tests include cases where the sorting invariant is broken. 
// You can create such a tree by using an iterator to modify an element's 
// value after it is inserted, breaking the invariant.

TEST(test_check_sorting_invariant_with_modification) {
    BinarySearchTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    auto it = bst.find(10);
    if (it != bst.end()) {
        *it = 20; 
    }
    ASSERT_FALSE(bst.check_sorting_invariant());
}

TEST(test_deeply_skewed_tree) {
    BinarySearchTree<int> bst;
    for (int i = 1; i <= 10; ++i) {
        bst.insert(i);
    }
    ASSERT_EQUAL(bst.height(), 10); 
    ASSERT_EQUAL(*bst.max_element(), 10);
    ASSERT_EQUAL(*bst.min_element(), 1);
    std::ostringstream os;
    bst.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), "1 2 3 4 5 6 7 8 9 10 ");
}

TEST_MAIN()
