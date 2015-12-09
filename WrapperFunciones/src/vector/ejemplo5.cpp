/*
 * ejemplo5.cpp
 *
 *  Created on: Dec 8, 2015
 *      Author: Pedro Valiente Verde
 */

#include <iostream>
#include <string>

#include <boost/python.hpp>

#include <boost/assign/std/vector.hpp>

using namespace boost::assign;
namespace py = boost::python;

std::vector<double> multiplicacion(const std::vector<double> &datos,
		double factor = 1) {
	std::vector<double> datos_transformados(datos);

	std::transform(datos_transformados.begin(), datos_transformados.end(),
			datos_transformados.begin(),
			[&factor](auto a) {return (a*factor);});

	return datos_transformados;
}

void test_multiplicacion() {
	std::vector<double> datos;
	datos += 1.0, 2.0, 3.0, 4.0;
	double factor(2);

	auto nuevos_datos = multiplicacion(datos, factor);

	std::cout << "Datos originales:" << std::endl;
	std::copy(datos.begin(), datos.end(),
			std::ostream_iterator<double>(std::cout, " "));
	std::cout << std::endl
			<< "Datos transformados, multiplicados por el factor: " << factor
			<< std::endl;
	std::copy(nuevos_datos.begin(), nuevos_datos.end(),
			std::ostream_iterator<double>(std::cout, " "));
}

BOOST_PYTHON_MODULE(ejemplo5)
{
	py::def("test_multiplicacion", test_multiplicacion);
}
