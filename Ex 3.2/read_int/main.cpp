//

// main.cpp

// ReadInt test

//

#include "gtest/gtest.h"
#include <iostream>
#include "readint.h"
#include <sstream>
using namespace std;

//expecting answer to be zero
TEST(readintTest, LegalTests) {
    stringstream ss;
    ss << "Hello\n1";
    ss.seekg(0,ss.beg);
    streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
    if(read_int("My Prompt: ", -3, 3) != 0)
    {
        cout << "Error did not return zero" << endl;
    }
    cin.rdbuf(orig_cin);
}

TEST(readintTest,rangeException){
    EXPECT_ANY_THROW({
        read_int("My Prompt: ", 5, 1);
    });
}

TEST(readintTest, valid){
      stringstream s;
    s << "-3\n5\n10\n-2\n3";
    s.seekg(0,s.beg);
    streambuf *orig_cin = cin.rdbuf(s.rdbuf());
    EXPECT_EQ(3, read_int("My Prompt: ", 0, 4));
    cin.rdbuf(orig_cin);
}

TEST(readintTest,rangeProblem){
    EXPECT_ANY_THROW({
        read_int("My Prompt: ", 0, 0);
    });
}


int main(int argc, char *argv[]) {
    
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
    
}
