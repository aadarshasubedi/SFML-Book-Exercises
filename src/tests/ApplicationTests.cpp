#include <gtest/gtest.h>

#include "../Application.hpp"

TEST(ApplicationTests, testApplicationCreated) { 
    auto app = new Application();
    ASSERT_NE(nullptr, app);    
    delete app;
}

TEST(DISABLE_ApplicationTests, testRunningApplication){
    auto app = new Application();
    ASSERT_DEATH(app->run(), "");
    delete app;
}
