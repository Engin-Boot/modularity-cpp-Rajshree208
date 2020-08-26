#include <iostream>
#include <assert.h>
#include "GetColorPairs.h"

void testNumberToPair(int pairNumber,
    TelCoColorCoder::MajorColor expectedMajor,
    TelCoColorCoder::MinorColor expectedMinor)
{
    TelCoColorCoder::ColorPair colorPair =
        TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(
    TelCoColorCoder::MajorColor major,
    TelCoColorCoder::MinorColor minor,
    int expectedPairNumber)
{
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

void getAllPairsInString()
{
    std::cout<<"-----REFERENCE MANUAL-----"<<std::endl;
    std::string refManual = "";
    noOfColorPairs = TelCoColorCoder::numberOfMinorColors*TelCoColorCoder::numberOfMajorColors;
    for(int pairNo = 1; pairNo <= noOfColorPairs; pairNo++)
    {
        TelCoColorCoder::ColorPair majorMinorColorPair = TelCoColorCoder::GetColorFromPairNumber(pairNo);
        refManual += "("+std::to_string(pairNo)+"->"+majorMinorColorPair.ToString()+")";
    }
    std::cout<<refManual<<std::endl;
}

int main() {
    testNumberToPair(4, TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);
    getAllPairsInString();
    return 0;
}
