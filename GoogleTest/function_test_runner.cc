#include "../AvlTree/OSAP_002_T6_source.h"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

class AvlTreeTestFixture : public testing::Test{
  public:
  AvlTreeTestFixture();
  virtual ~AvlTreeTestFixture();
  void SetUp() override;
  void TearDown() override;
  static void SetUpTestCase();
  static void TearDownTestCase();

  protected:
    AvlTree tree_;
    AvlTree emptyTree_;

    std::ostringstream total_output_, output_unexceptable_;
    std::streambuf* original_buffer_;
};

AvlTreeTestFixture::AvlTreeTestFixture() {
  std::cout << "Constructor called\n";
}

AvlTreeTestFixture::~AvlTreeTestFixture() {
  std::cout << "Destructor called\n";
}

void AvlTreeTestFixture::SetUpTestCase() {
  std::cout << "SetUpTestCase called\n";
}

void AvlTreeTestFixture::TearDownTestCase() {
  std::cout << "TearDownTestCase called\n";
}

void AvlTreeTestFixture::SetUp() {
  original_buffer_ = std::cout.rdbuf();
  std::cout.rdbuf(output_unexceptable_.rdbuf());
  for(int i = 1; i < 8; i++)
    tree_.Insert(i);

  original_buffer_ = std::cout.rdbuf();
  std::cout.rdbuf(total_output_.rdbuf());
}

void AvlTreeTestFixture::TearDown() {
  std::cout.rdbuf(original_buffer_);
}

//Test Find
TEST_F(AvlTreeTestFixture, TestFind) { //** */
  for(int i = 1; i < 8; i++)
    tree_.Find(i);
  std::string saved_output = total_output_.str();
  ASSERT_EQ("3\n3\n3\n3\n3\n3\n3\n",saved_output);
}

//Test Empty
TEST_F(AvlTreeTestFixture, TestEmpty) {//*
  tree_.Empty();
  emptyTree_.Empty();
  std::string saved_output = total_output_.str();
  ASSERT_EQ("0\n1\n",saved_output);
}


//Test Size
TEST_F(AvlTreeTestFixture, TestSize) {//*
  tree_.Size();
  emptyTree_.Size();
  std::string saved_output = total_output_.str();
  ASSERT_EQ("7\n0\n",saved_output);
}

//Test Height
TEST_F(AvlTreeTestFixture, TestHeight) {//*
  tree_.Height();
  emptyTree_.Height();
  std::string saved_output = total_output_.str();
  ASSERT_EQ("3\n-1\n",saved_output);
}

//Test Ancestor
TEST_F(AvlTreeTestFixture, TestAncestor) {//*
  tree_.Ancestor(4);
  std::string saved_output = total_output_.str();
  ASSERT_EQ("3 0\n",saved_output);
}

//Test Average
TEST_F(AvlTreeTestFixture, TestAverage) {//*
  tree_.Average(4);
  std::string saved_output = total_output_.str();
  ASSERT_EQ("4\n",saved_output);
}

//Test Rank Operations
TEST_F(AvlTreeTestFixture, TestRank) {//*
  tree_.Rank(1);
  tree_.Rank(8);
  std::string saved_output = total_output_.str();
  ASSERT_EQ("3 1\n0\n",saved_output);
}
TEST_F(AvlTreeTestFixture, TestCalculateRank) { //*
  ASSERT_EQ(3,tree_.CalculateRank(tree_.getRoot(),3));
}

//Test Path Calculations
TEST_F(AvlTreeTestFixture, TestGetPathToRootSum) {//*
  EXPECT_EQ(7, AvlTreeUtils::GetPathToRootSum(
    AvlTreeUtils::FindNodeByValue(tree_.getRoot(),1)));
}


TEST_F(AvlTreeTestFixture, TestGetSize) {//*
  EXPECT_EQ(7, AvlTreeMetrics::GetSize(
    AvlTreeUtils::FindNodeByValue(tree_.getRoot(),4)));

  EXPECT_EQ(0, AvlTreeMetrics::GetSize(
    AvlTreeUtils::FindNodeByValue(emptyTree_.getRoot(),4)));
}

//Test Height and Depth Operations
TEST_F(AvlTreeTestFixture, TestCalculateDepth) {//*
  EXPECT_EQ(0,AvlTreeMetrics::CalculateDepth(
    AvlTreeUtils::FindNodeByValue(tree_.getRoot(),4)));

  EXPECT_EQ(0,AvlTreeMetrics::CalculateDepth(nullptr));
}

TEST_F(AvlTreeTestFixture, TestGetHeight) {//*
  EXPECT_EQ(3,AvlTreeMetrics::GetHeight(
    AvlTreeUtils::FindNodeByValue(tree_.getRoot(),4)));
  
  EXPECT_EQ(0,AvlTreeMetrics::GetHeight(nullptr));
}

//Test Balance Analysis
TEST_F(AvlTreeTestFixture, TestCalculateBalanceFactor) {//*
  EXPECT_EQ(0, AvlTreeRotate::CalculateBalanceFactor(
    AvlTreeUtils::FindNodeByValue(tree_.getRoot(),1)));
  EXPECT_EQ(0, AvlTreeRotate::CalculateBalanceFactor(nullptr));
}

//Test Insert
TEST_F(AvlTreeTestFixture, TestInsert) {
  //이미 있는 값을 줬을때
  tree_.Insert(1);
  AvlTree treeForTestInsertLL;
  treeForTestInsertLL.Insert(5);
  treeForTestInsertLL.Insert(6);
  treeForTestInsertLL.Insert(3);
  treeForTestInsertLL.Insert(4);
  treeForTestInsertLL.Insert(2);
  treeForTestInsertLL.Insert(1);
  AvlTree treeForTestInsertLR;
  treeForTestInsertLR.Insert(5);
  treeForTestInsertLR.Insert(6);
  treeForTestInsertLR.Insert(2);
  treeForTestInsertLR.Insert(1);
  treeForTestInsertLR.Insert(4);
  treeForTestInsertLR.Insert(3);
  AvlTree treeForTestInsertRR;
  treeForTestInsertRR.Insert(2);
  treeForTestInsertRR.Insert(1);
  treeForTestInsertRR.Insert(4);
  treeForTestInsertRR.Insert(3);
  treeForTestInsertRR.Insert(6);
  treeForTestInsertRR.Insert(5);
  AvlTree treeForTestInsertRL;
  treeForTestInsertRL.Insert(2);
  treeForTestInsertRL.Insert(1);
  treeForTestInsertRL.Insert(5);
  treeForTestInsertRL.Insert(6);
  treeForTestInsertRL.Insert(4);
  treeForTestInsertRL.Insert(3);
  std::string saved_output = total_output_.str();
  ASSERT_EQ("1\n2\n2\n3\n3\n3\n1\n2\n2\n3\n3\n3\n1\n2\n2\n3\n3\n3\n1\n2\n2\n3\n3\n3\n",saved_output);
}

//Test Erase
TEST_F(AvlTreeTestFixture, TestErase) {
  0, tree_.Erase(1000);
  AvlTree treeForTestEraseLL;
  treeForTestEraseLL.Insert(5);
  treeForTestEraseLL.Insert(6);
  treeForTestEraseLL.Insert(3);
  treeForTestEraseLL.Insert(7);
  treeForTestEraseLL.Insert(4);
  treeForTestEraseLL.Insert(2);
  treeForTestEraseLL.Insert(1);
  treeForTestEraseLL.Erase(7);
  AvlTree treeForTestEraseLR;
  treeForTestEraseLR.Insert(5);
  treeForTestEraseLR.Insert(6);
  treeForTestEraseLR.Insert(2);
  treeForTestEraseLR.Insert(7);
  treeForTestEraseLR.Insert(1);
  treeForTestEraseLR.Insert(4);
  treeForTestEraseLR.Insert(3);
  treeForTestEraseLR.Erase(7);
  AvlTree treeForTestEraseRR;
  treeForTestEraseRR.Insert(3);
  treeForTestEraseRR.Insert(2);
  treeForTestEraseRR.Insert(5);
  treeForTestEraseRR.Insert(1);
  treeForTestEraseRR.Insert(4);
  treeForTestEraseRR.Insert(7);
  treeForTestEraseRR.Insert(6);
  treeForTestEraseRR.Erase(1);
  AvlTree treeForTestEraseRL;
  treeForTestEraseRL.Insert(3);
  treeForTestEraseRL.Insert(2);
  treeForTestEraseRL.Insert(6);
  treeForTestEraseRL.Insert(1);
  treeForTestEraseRL.Insert(7);
  treeForTestEraseRL.Insert(5);
  treeForTestEraseRL.Insert(4);
  treeForTestEraseRL.Erase(1);
  std::string saved_output = total_output_.str();
  ASSERT_EQ("0\n1\n2\n2\n3\n3\n3\n4\n3\n1\n2\n2\n3\n3\n3\n4\n3\n1\n2\n2\n3\n3\n3\n4\n3\n1\n2\n2\n3\n3\n3\n4\n3\n",saved_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
