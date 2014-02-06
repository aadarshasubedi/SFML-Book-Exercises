#include <gtest/gtest.h>

#include "../Application.hpp"

TEST(ApplicationTests, testApplicationCreated) { 
    auto app = new Application();
    ASSERT_NE(nullptr, app);    
    delete app;
}
 

