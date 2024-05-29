//calculating the total size of an image based on its width, height, and channel size.

#include <iostream>

int main ()
{
    std::uint16_t width =0;
    std::uint16_t height =0;
    constexpr int16_t channel_size = 8;
    constexpr int16_t num_of_channels = 3;  //compile time only
    std::uint16_t total_num_of_bits = 0;    //compile time only
    
    //the user enter width and height of image 
    //enter width 
    std::cout << "Please Enter Width:" <<std::endl;
    std::cin >> width;
    //enter height
    std::cout <<"Please Enter Height:" <<std::endl;
    std::cin >> height;

    //calculat num f pixels in image
    total_num_of_bits = channel_size * num_of_channels * width * height ;
    
    //print the result from calculation
    std::cout << "Total Size is " << total_num_of_bits << " bits" << std::endl;

    return 0;
}
