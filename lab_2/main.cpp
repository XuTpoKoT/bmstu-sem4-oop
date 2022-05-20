#include <iostream>
#include <cstdlib>

#include "Vector.hpp"

int main()
{
    setbuf(stdout, NULL);

    try {
        Vector<double> initializing = {5, 2, 15};
        const Vector<int> constVect{0, 1, 2, 3, 4};
        Vector<float> lenExample(3);
        Vector<double> lenFillExample(3, 4.91, 7.5, 8.6);

        std::cout<< "Vector with initialization: "<< initializing << std::endl;
        std::cout<< "Vector with a given length: "<< lenExample << std::endl;
        std::cout<< "Vector of a given length with initialization: "<< lenFillExample<< std::endl;

        Vector<double> v1 = {4, 2, 4};
        Vector<double> v2 = {3, 1, 5};
        Vector<double> v3 = {1.0, 2.0, 1.0};

        std::cout<< "Normalization of the vector: "<< v2 << "=>" << v2.get_single() << std::endl;
        std::cout<< "Size vector: " << initializing.getSize()<< std::endl;
        std::cout<< "Vector length: "<<initializing.lenght()<< std::endl;
        std::cout<< "Is a single vector: "<<initializing.is_unit()<< std::endl;
        std::cout<< "Angle between vectors: "<< lenFillExample.angle(initializing)<< std::endl;

        initializing.set_element(1, 10);
        std::cout<< "The second element of the vector: "<< initializing.get_element(1)<< std::endl;
        std::cout<< "The second element of the constant vector: "<< constVect.get_element(1)<< std::endl;

        std::cout<< "Vectors +: "<< v1 << " + " <<  v2 << " = " << v1 + v2<< std::endl;
        std::cout<< "Vectors -: "<< v1 << " - " <<  v2 << " = " << v1 - v2<< std::endl;
        std::cout<< "Vectors *: "<< v1 << " * " <<  v2 << " = " << v1 * v2<< std::endl;
        std::cout<< "Vectors ^: "<< v1 << " ^ " <<  v2 << " = " << (v1 ^ v2) << std::endl;
        std::cout<< "Vectors |: "<< v1 << " ^ " <<  v2 << " = " << (v1 | v2) << std::endl;
        std::cout<< "Vectors /: "<< v1 << " ^ " <<  v2 << " = " << (v1 / v2) << std::endl;

        std::cout<< "Vector + 5: "<< v1 << " + 5 = " << v1 + 5<< std::endl;
        std::cout<< "Vector - 5: "<< v1 << " - 5 = " << v1 - 5<< std::endl;
        std::cout<< "Vector ^ 5: "<< v1 << " ^ 5 = " << (v1 ^ 5) << std::endl;
        std::cout<< "Vector / 5: "<< v1 << " / 5 = " << (v1 / 5) << std::endl;

        Vector<float> orthVecF = {1, 0, 0};
        Vector<float> orthVecS = {0, 1, 0};
        Vector<float> nonOrthVec = {1, 2, 3};

        std::cout<< "Orthogonality: "<< orthVecF.is_orthogonality(orthVecS)<< std::endl;
        std::cout<< "Not orthogonality: "<<orthVecF.is_orthogonality(nonOrthVec)<< std::endl;

        Vector<int> colVecF = {1, 1, 0};
        Vector<int> colVecS = {1, 1, 0};
        Vector<int> colVecT = {1, 0, 3};

        std::cout<< "Collinearity: "<< colVecF.is_collinearity(colVecS)<< std::endl;
        std::cout<< "Not collinearity: "<< colVecF.is_collinearity(colVecT)<< std::endl;

        try {
            std::cout<< v3 / 0 << std::endl;
        } catch (VectorException &er) {
                std::cout<< "\nFind error:"<< er.what()<< std::endl;
        }

    }  catch (std::exception &er) {
       std::cout<< "error:"<< er.what()<< std::endl;
    }

    return 0;
}
