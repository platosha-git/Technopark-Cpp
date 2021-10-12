#include <gtest/gtest.h>
#include "../exit_codes.h"
#include "../correct_input.c"

//строка
TEST(SEARCH_TEST, CORRECT_STR) {
        EXPECT_EQ(is_correct_string("success"), true);
}

TEST(SEARCH_TEST, INCORRECT_STR) {
        EXPECT_EQ(is_correct_string("success2"), false);
}

//число
TEST(SEARCH_TEST, CORRECT_NUM) {
    	EXPECT_EQ(is_correct_number(1), true);
}

TEST(SEARCH_TEST, INCORRECT_NUM) {
        EXPECT_EQ(is_correct_number(-1), false);
}

//день
TEST(SEARCH_TEST, CORRECT_DAY) {
        EXPECT_EQ(is_correct_day("11-11-2011"), true);
}

TEST(SEARCH_TEST, INCORRECT_DAY) {
        EXPECT_EQ(is_correct_day("32-11-2011"), false);
}

//месяц
TEST(SEARCH_TEST, CORRECT_MONTH) {
        EXPECT_EQ(is_correct_month("11-11-2011"), true);
}

TEST(SEARCH_TEST, INCORRECT_MONTH) {
        EXPECT_EQ(is_correct_month("11-13-2011"), false);
}

//год
TEST(SEARCH_TEST, CORRECT_YEAR) {
        EXPECT_EQ(is_correct_year("11-11-2021"), true);
}

TEST(SEARCH_TEST, INCORRECT_YEAR) {
        EXPECT_EQ(is_correct_year("11-11-2023"), false);
}

//дата
TEST(SEARCH_TEST, CORRECT_DATE) {
        EXPECT_EQ(correct_date("11-11-2011"), SUCCESS);
}

TEST(SEARCH_TEST, INCORRECT_DATE) {
        EXPECT_EQ(correct_date("11.11.2011"), DATE_ERR);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
