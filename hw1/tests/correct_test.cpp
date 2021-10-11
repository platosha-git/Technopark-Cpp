#include <gtest/gtest.h>
#include "../exit_codes.h"
#include "../correct_input.c"

//строка
TEST(SEARCH_TEST, Correct_str) {
        EXPECT_EQ(correct_string("success"), SUCCESS);
}

TEST(SEARCH_TEST, Incorrect_str) {
        EXPECT_EQ(correct_string("success2"), STRING_ERR);
}

//число
TEST(SEARCH_TEST, Correct_num) {
    	EXPECT_EQ(correct_number(1), SUCCESS);
}

TEST(SEARCH_TEST, Incorrect_num) {
        EXPECT_EQ(correct_number(-1), COUNT_ERR);
}

//день
TEST(SEARCH_TEST, Correct_day) {
        EXPECT_EQ(is_correct_day("11-11-2011"), true);
}

TEST(SEARCH_TEST, Incorrect_day) {
        EXPECT_EQ(is_correct_day("32-11-2011"), false);
}

//месяц
TEST(SEARCH_TEST, Correct_month) {
        EXPECT_EQ(is_correct_month("11-11-2011"), true);
}

TEST(SEARCH_TEST, Incorrect_month) {
        EXPECT_EQ(is_correct_month("11-13-2011"), false);
}

//год
TEST(SEARCH_TEST, Correct_year) {
        EXPECT_EQ(is_correct_year("11-11-2021"), true);
}

TEST(SEARCH_TEST, Incorrect_year) {
        EXPECT_EQ(is_correct_year("11-11-2023"), false);
}

//дата
TEST(SEARCH_TEST, Correct_date) {
        EXPECT_EQ(correct_date("11-11-2011"), SUCCESS);
}

TEST(SEARCH_TEST, Incorrect_date) {
        EXPECT_EQ(correct_date("11.11.2011"), DATE_ERR);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
