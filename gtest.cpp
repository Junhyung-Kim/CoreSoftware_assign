#include <gtest/gtest.h>
#include "assign4.h"

void Count_Word (FILE *f, vector <int> &v, vector <string> &k);

FILE *f = fopen("Aladdin.txt", "r");

//Test descending order
TEST(Count_Word_test,Check_descending){
    Count_Word(f,v,k);
    EXPECT_GE(v[0],v[1]);
    EXPECT_GE(v[100],v[101]);
    EXPECT_GE(v[150],v[151]);
}

//Test key value
TEST(Count_Word_test2,Check_key){
    Count_Word(f,v,k);
    ASSERT_EQ(k[0],"the");
    ASSERT_EQ(k[2],"to");
    ASSERT_EQ(k[4],"aladdin");
}

//Test check value
TEST(Count_Word_test3,Check_value){
    Count_Word(f,v,k);
    EXPECT_TRUE(v[0] == 869);
    EXPECT_TRUE(v[2] == 448);
    EXPECT_TRUE(v[4] == 383);
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
