


#include "gtest/gtest.h"
#include "PBlocksDisplay.h"


class obj {
};


TEST(TestTouchRegion, constructDeconstructRegions) {
  TouchHandler touchHandler;

  EXPECT_EQ(0, touchHandler.getRegionCount());
  {
    TouchRegion<obj> r1;
    EXPECT_EQ(1, touchHandler.getRegionCount());

    {
      TouchRegion<obj> r2;
      EXPECT_EQ(2, touchHandler.getRegionCount());
    }

    EXPECT_EQ(1, touchHandler.getRegionCount());
  }

  EXPECT_EQ(0, touchHandler.getRegionCount());
}




TEST(TestTouchRegion, constructDeconstructDynamicallyOutOfOrder) {
  TouchHandler touchHandler;

  TouchRegion<obj> * r1 = nullptr;
  TouchRegion<obj> * r2 = nullptr;
  TouchRegion<obj> * r3 = nullptr;

  EXPECT_EQ(0, touchHandler.getRegionCount());

  r1 = new TouchRegion<obj>();
  EXPECT_EQ(1, touchHandler.getRegionCount());
  r2 = new TouchRegion<obj>();
  EXPECT_EQ(2, touchHandler.getRegionCount());
  r3 = new TouchRegion<obj>();
  EXPECT_EQ(3, touchHandler.getRegionCount());

  delete r2;
  EXPECT_EQ(2, touchHandler.getRegionCount());
  delete r1;
  EXPECT_EQ(1, touchHandler.getRegionCount());
  r2 = new TouchRegion<obj>();
  EXPECT_EQ(2, touchHandler.getRegionCount());
  delete r3;
  EXPECT_EQ(1, touchHandler.getRegionCount());
  delete r2;
  EXPECT_EQ(0, touchHandler.getRegionCount());
}




