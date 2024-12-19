/*
MIT License

Copyright (c) 2024 INHA_OSAP_002_T6

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Author: INHA_OSAP_002_T6
Date: 2024-11-20
*/
#include <gtest/gtest.h>

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "../AvlTree/OSAP_002_T6_source.h"

/**
 * @brief Test that testing all funtion at least once 
 */
TEST(AvlTreeTest, TotalTest) {
  AvlTree tree_;
  std::ostringstream total_output_;
  std::streambuf *original_buffer_;
  original_buffer_ = std::cout.rdbuf();
  std::cout.rdbuf(total_output_.rdbuf());
  tree_.Empty();
  tree_.Height();
  tree_.Rank(5);
  tree_.Insert(91);
  tree_.Insert(24);
  tree_.Insert(94);
  tree_.Insert(74);
  tree_.Insert(28);
  tree_.Insert(96);
  tree_.Insert(19);
  tree_.Insert(1);
  tree_.Insert(50);
  tree_.Insert(65);
  tree_.Insert(13);
  tree_.Insert(9);
  tree_.Insert(31);
  tree_.Insert(4);
  tree_.Empty();
  tree_.Insert(5);
  tree_.Insert(47);
  tree_.Insert(8);
  tree_.Insert(75);
  tree_.Insert(82);
  tree_.Insert(76);
  tree_.Height();
  tree_.Insert(63);
  tree_.Insert(86);
  tree_.Insert(57);
  tree_.Insert(36);
  tree_.Insert(68);
  tree_.Insert(85);
  tree_.Insert(73);
  tree_.Insert(46);
  tree_.Insert(72);
  tree_.Insert(21);
  tree_.Insert(64);
  tree_.Insert(10);
  tree_.Insert(66);
  tree_.Insert(40);
  tree_.Insert(15);
  tree_.Insert(77);
  tree_.Insert(61);
  tree_.Rank(77);
  tree_.Insert(59);
  tree_.Insert(18);
  tree_.Empty();
  tree_.Insert(70);
  tree_.Insert(38);
  tree_.Insert(49);
  tree_.Insert(20);
  tree_.Insert(14);
  tree_.Insert(69);
  tree_.Insert(60);
  tree_.Insert(99);
  tree_.Insert(37);
  tree_.Insert(80);
  tree_.Insert(71);
  tree_.Insert(58);
  tree_.Insert(43);
  tree_.Insert(92);
  tree_.Insert(23);
  tree_.Insert(98);
  tree_.Insert(3);
  tree_.Insert(55);
  tree_.Insert(45);
  tree_.Insert(62);
  tree_.Insert(89);
  tree_.Insert(42);
  tree_.Insert(41);
  tree_.Insert(100);
  tree_.Insert(6);
  tree_.Insert(11);
  tree_.Insert(29);
  tree_.Insert(78);
  tree_.Insert(26);
  tree_.Insert(7);
  tree_.Insert(39);
  tree_.Insert(54);
  tree_.Insert(30);
  tree_.Find(44);
  tree_.Insert(83);
  tree_.Insert(25);
  tree_.Insert(35);
  tree_.Empty();
  tree_.Insert(44);
  tree_.Insert(84);
  tree_.Insert(88);
  tree_.Insert(16);
  tree_.Insert(2);
  tree_.Insert(97);
  tree_.Insert(56);
  tree_.Find(3);
  tree_.Insert(34);
  tree_.Insert(22);
  tree_.Insert(53);
  tree_.Ancestor(1);
  tree_.Insert(90);
  tree_.Insert(93);
  tree_.Insert(27);
  tree_.Insert(87);
  tree_.Insert(33);
  tree_.Insert(79);
  tree_.Insert(51);
  tree_.Insert(12);
  tree_.Insert(81);
  tree_.Insert(17);
  tree_.Height();
  tree_.Insert(67);
  tree_.Insert(52);
  tree_.Insert(48);
  tree_.Insert(32);
  tree_.Insert(95);
  tree_.Find(1);
  tree_.Find(2);
  tree_.Erase(10);
  tree_.Erase(77);
  tree_.Erase(42);
  tree_.Erase(73);
  tree_.Erase(88);
  tree_.Erase(11);
  tree_.Erase(55);
  tree_.Erase(57);
  tree_.Erase(89);
  tree_.Rank(27);
  tree_.Erase(27);
  tree_.Erase(19);
  tree_.Erase(94);
  tree_.Average(50);
  tree_.Ancestor(43);
  tree_.Erase(33);
  tree_.Erase(7);
  tree_.Erase(43);
  tree_.Erase(36);
  tree_.Erase(46);
  tree_.Erase(14);
  tree_.Erase(92);
  tree_.Erase(8);
  tree_.Erase(79);
  tree_.Erase(39);
  tree_.Erase(96);
  tree_.Erase(18);
  tree_.Height();
  tree_.Erase(20);
  tree_.Erase(90);
  tree_.Empty();
  tree_.Erase(26);
  tree_.Erase(63);
  tree_.Erase(81);
  tree_.Erase(15);
  tree_.Erase(29);
  tree_.Erase(50);
  tree_.Erase(95);
  tree_.Erase(69);
  tree_.Erase(75);
  tree_.Rank(93);
  tree_.Erase(93);
  tree_.Erase(56);
  tree_.Erase(80);
  tree_.Erase(98);
  tree_.Erase(24);
  tree_.Erase(48);
  tree_.Erase(22);
  tree_.Ancestor(41);
  tree_.Erase(68);
  tree_.Erase(35);
  tree_.Erase(51);
  tree_.Erase(16);
  tree_.Erase(4);
  tree_.Erase(54);
  tree_.Erase(65);
  tree_.Erase(32);
  tree_.Erase(38);
  tree_.Erase(76);
  tree_.Erase(31);
  tree_.Erase(84);
  tree_.Erase(78);
  tree_.Erase(5);
  tree_.Erase(44);
  tree_.Erase(60);
  tree_.Erase(41);
  tree_.Erase(34);
  tree_.Erase(52);
  tree_.Erase(45);
  tree_.Erase(58);
  tree_.Erase(17);
  tree_.Erase(87);
  tree_.Erase(62);
  tree_.Erase(67);
  tree_.Erase(25);
  tree_.Erase(82);
  tree_.Erase(30);
  tree_.Ancestor(9);
  tree_.Erase(53);
  tree_.Erase(37);
  tree_.Erase(3);
  tree_.Erase(40);
  tree_.Erase(66);
  tree_.Erase(59);
  tree_.Erase(9);
  tree_.Erase(6);
  tree_.Erase(2);
  tree_.Erase(97);
  tree_.Erase(49);
  tree_.Erase(28);
  tree_.Empty();
  tree_.Erase(91);
  tree_.Erase(85);
  tree_.Ancestor(100);
  tree_.Erase(23);
  tree_.Erase(83);
  tree_.Erase(21);
  tree_.Erase(12);
  tree_.Erase(13);
  tree_.Average(70);
  tree_.Erase(47);
  tree_.Erase(70);
  tree_.Erase(61);
  tree_.Erase(71);
  tree_.Erase(100);
  tree_.Erase(72);
  tree_.Erase(1);
  tree_.Erase(64);
  tree_.Erase(86);
  tree_.Erase(99);
  tree_.Erase(74);
  std::string saved_output = total_output_.str();
  ASSERT_EQ(
      "1\n-"
      "1\n0\n1\n2\n2\n3\n3\n3\n4\n4\n4\n4\n4\n4\n5\n4\n0\n4\n5\n5\n5\n5\n5\n5\n"
      "5\n5\n6\n5\n6\n6\n6\n6\n6\n6\n5\n6\n6\n5\n6\n6\n6\n6 "
      "31\n6\n6\n0\n6\n6\n6\n5\n6\n7\n6\n5\n6\n6\n7\n7\n7\n6\n6\n6\n6\n7\n7\n6"
      "\n6\n7\n7\n6\n6\n6\n6\n7\n7\n7\n6\n7\n7\n0\n7\n7\n7\n0\n7\n7\n7\n7\n6\n7"
      "\n7\n6\n7\n8\n7\n6 "
      "84\n7\n6\n8\n8\n7\n7\n7\n6\n7\n7\n8\n7\n7\n8\n7\n7\n6\n6\n6\n7\n8\n6\n8"
      "\n6\n7\n7\n7\n8 25\n8\n8\n7\n50\n7 "
      "106\n7\n7\n7\n7\n7\n6\n6\n6\n7\n7\n7\n6\n7\n7\n7\n0\n7\n7\n6\n6\n7\n7\n6"
      "\n7\n7\n5 61\n5\n7\n6\n6\n7\n7\n7\n6 "
      "193\n7\n6\n7\n6\n6\n6\n7\n6\n6\n7\n6\n6\n7\n6\n6\n7\n6\n5\n6\n6\n6\n5\n6"
      "\n6\n5\n6\n6\n5\n6 74\n6\n5\n6\n5\n6\n5\n5\n5\n5\n5\n4\n4\n0\n5\n5\n4 "
      "243\n4\n5\n4\n4\n4\n50\n4\n4\n3\n4\n4\n3\n3\n2\n2\n2\n1\n",
      saved_output);
  std::cout.rdbuf(original_buffer_);
}

/**
 * @brief Main function starting the test
 */
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
