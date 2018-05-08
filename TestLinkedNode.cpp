#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

#include "LinkedNode.h"

using namespace CppUnit;
using namespace std;

#define INT_DATA 3
#define INT_DATA_2 1265

class TestLinkedNode : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestLinkedNode);
    CPPUNIT_TEST(test_constructor_1);
    CPPUNIT_TEST(test_set_next);
    CPPUNIT_TEST(test_set_previous);
    CPPUNIT_TEST(test_equals);
    CPPUNIT_TEST_SUITE_END();

    public:
        void setUp(void);
        void tearDown(void);
    protected:
        void test_constructor_1(void);
        void test_set_next(void);
        void test_set_previous(void);
        void test_get_data(void); // Probably unneeded
        void test_equals(void);
    private:
        LinkedNode<int>* linked_node_int;
};

void TestLinkedNode::setUp(void) {
    linked_node_int = new LinkedNode<int>(INT_DATA);
}

void TestLinkedNode::tearDown(void) {

}

CPPUNIT_TEST_SUITE_REGISTRATION(TestLinkedNode);

/*
Create some linkedlists and test they are setup correclty, note however these tests require the 
get data functionality and the == operator to be working.
*/
void TestLinkedNode::test_constructor_1(void) {
    // Use some constructors
    LinkedNode<int>* test_node_1 = new LinkedNode<int>(INT_DATA);
    LinkedNode<int>* test_node_2 = new LinkedNode<int>(INT_DATA_2);
    LinkedNode<int>* test_node_3 = new LinkedNode<int>(INT_DATA, test_node_1, test_node_2);

    // We should get the following data
    CPPUNIT_ASSERT(test_node_1->getData() == INT_DATA);
    CPPUNIT_ASSERT(test_node_2->getData() == INT_DATA_2);
    CPPUNIT_ASSERT(test_node_3->getData() == INT_DATA);

    // The following previous's
    CPPUNIT_ASSERT(test_node_1->previous == NULL);
    CPPUNIT_ASSERT(test_node_2->previous == NULL);
    CPPUNIT_ASSERT(test_node_3->previous == test_node_2);

    // The following next's
    CPPUNIT_ASSERT(test_node_1->next == NULL);
    CPPUNIT_ASSERT(test_node_2->next == NULL);
    CPPUNIT_ASSERT(test_node_3->next == test_node_1);
}

void TestLinkedNode::test_set_next(void) {
    LinkedNode<int>* next_node = new LinkedNode<int>(INT_DATA);
    linked_node_int->setNext(next_node);
    CPPUNIT_ASSERT(linked_node_int->next == next_node);
}

void TestLinkedNode::test_set_previous(void) {
    LinkedNode<int>* previous_node = new LinkedNode<int>(INT_DATA);
    linked_node_int->setPrevious(previous_node);
    CPPUNIT_ASSERT(linked_node_int->previous == previous_node);
}

void TestLinkedNode::test_equals(void) {
    LinkedNode<int>* same_node = new LinkedNode<int>(INT_DATA);
    CPPUNIT_ASSERT(*linked_node_int == *same_node);

}

int main(int argc, char* argv[])
{
    CppUnit::TextUi::TestRunner testrunner;
    testrunner.addTest(TestLinkedNode::suite());
    testrunner.run();
    return 0;
}