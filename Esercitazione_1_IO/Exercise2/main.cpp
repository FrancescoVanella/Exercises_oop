
#include <iostream>
#include <fstream>


int main()
{

    std::string inputFileName = "data.csv"; // file name
    std::ifstream ifstr(inputFileName); // open file

    if(ifstr.fail())
    {
        std::cerr << "Input file does not exist" << std::endl;
        return 1;
    }


    std::string outputFileName = "result.csv"; // file name
    std::ofstream ofstr(outputFileName); // open file

    if(ofstr.fail())
    {
        std::cerr << "Output file does not exist" << std::endl;
        return 1;
    }

    long double x = 0;
    unsigned int N = 0;
    long double y = 0;
    long double sum = 0;
    long double mean = 0;
    ofstr <<std::endl;
    ofstr <<"# "<< N << " Mean"<<std::endl;

    while(ifstr >> x){

        y=(x-1)*3/4-1;
        sum+=y;
        N++;
        mean=sum/N;
        ofstr << mean <<std::endl;

    }
    ifstr.close();

    ofstr.seekp(0);
    // Scrive una nuova riga all'inizio del file
    ofstr <<"# "<< N << " Mean"<<std::endl;
    ofstr.close();

    return 0;
}
