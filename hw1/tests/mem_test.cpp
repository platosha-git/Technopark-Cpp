#include <gtest/gtest.h>
#include "../exit_codes.h"
#include "../mem_operations.c"

TEST(SEARCH_TEST, Correct_create1) {
    struct contract *array = NULL;
    EXPECT_EQ(create_array(&array, 1), SUCCESS);
    free(array);
}

TEST(SEARCH_TEST, Correct_create2) {
    struct contract *array = NULL;
    create_array(&array, 1);
    
    array[0].sum = 1;
    EXPECT_EQ(array[0].sum, 1);
    free(array);
}

TEST(SEARCH_TEST, Correct_realloc) {
    struct contract *array = NULL;
    create_array(&array, 1);
    
    EXPECT_EQ(realloc_memory(&array, 2), SUCCESS);

    free(array);
}

TEST(SEARCH_TEST, Correct_increase) {
    struct contract *array = NULL;
    size_t max_size = 1;

    create_array(&array, 1);
    increase_memory(&array, &max_size, 1);

    array[1].sum = 1;
    EXPECT_EQ(array[1].sum, 1);

    free(array);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
