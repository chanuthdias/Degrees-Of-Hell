#include "RandomNumberGenerator.h"
#include <fstream>
#include <sstream>

int RandomNumberGenerator::Random( )
{
	return static_cast<int>( static_cast<double> ( rand( ) ) / ( RAND_MAX + 1 ) * 10.0f + 1 );
}

void RandomNumberGenerator::SetSeed( )
{
    string line;

    ifstream file( "seed.txt" );

    if ( !file.is_open( ) ) {
        cerr << "Error opening the file." << std::endl;
        return;
    }
    getline( file , line );
    srand( stoi( line ) );
}