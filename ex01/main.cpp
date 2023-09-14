/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:13:48 by rrhnizar          #+#    #+#             */
/*   Updated: 2023/09/14 23:16:46 by rrhnizar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	// Create a Data object
    Data data(42);

    // Serialize the Data object
    uintptr_t serializedData = Serializer::serialize(&data);
	std::cout << serializedData << std::endl;
	
    // Deserialize the serializedData
    // Data* deserializedData = Serializer::deserialize(serializedData);

    // // Check if deserializedData is equal to the original pointer
    // if (deserializedData == &data) 
	// {
    //     std::cout << "Serialization and deserialization worked correctly." << std::endl;
    //     std::cout << "Original Data value: " << data.value << std::endl;
    //     std::cout << "Deserialized Data value: " << deserializedData->value << std::endl;
    // } 
	// else
    //     std::cout << "Serialization and deserialization failed." << std::endl;
	return 0;
}