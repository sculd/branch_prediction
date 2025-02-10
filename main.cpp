#include <iostream>
#include <iterator> // Required for std::size
#include <vector>


void test(const int data[], const unsigned arraySize) {
    // Test
    clock_t start = clock();
    long long sum = 0;
    for (unsigned i = 0; i < 100000; ++i)
    {
        for (unsigned c = 0; c < arraySize; ++c)
        {
            if (data[c] >= 128)
                sum += data[c];
        }
    }

    double elapsedTime = static_cast<double>(clock()-start) / CLOCKS_PER_SEC;

    std::cout << elapsedTime << std::endl;
    std::cout << "sum = " << sum << std::endl;
}

void testTertinary(const int data[], const unsigned arraySize) {
    // Test
    clock_t start = clock();
    long long sum = 0;
    for (unsigned i = 0; i < 100000; ++i)
    {
        for (unsigned c = 0; c < arraySize; ++c)
        {
            sum += data[c] >= 128 ? data[c] : 0;
        }
    }

    double elapsedTime = static_cast<double>(clock()-start) / CLOCKS_PER_SEC;

    std::cout << elapsedTime << std::endl;
    std::cout << "sum = " << sum << std::endl;
}

/*
no sort 8.36228
tertinary no sort 12.0197

with sort 3.92989
tertinary with sort 4.40509
*/
int main()
{
    // Generate data
    const unsigned arraySize = 32768;
    int data[arraySize];

    for (unsigned c = 0; c < arraySize; ++c)
        data[c] = std::rand() % 256;

    std::cout << "no sort" << std::endl;
    test(data, arraySize);
    std::cout << "tertinary no sort" << std::endl;
    testTertinary(data, arraySize);

    // !!! With this, the next loop runs faster.
    std::cout << "sorting" << std::endl;
    std::sort(data, data + arraySize);
    std::cout << "with sort" << std::endl;
    test(data, arraySize);
    std::cout << "tertinary with sort" << std::endl;
    testTertinary(data, arraySize);

    return 0;
}
