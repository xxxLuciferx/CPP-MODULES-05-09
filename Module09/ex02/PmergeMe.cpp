/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:34:35 by khaimer           #+#    #+#             */
/*   Updated: 2024/05/12 23:46:34 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) 
{
	this->Before = other.Before;
	this->vec_pairs = other.vec_pairs;
	this->deq_pairs = other.deq_pairs;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) 
	{
		this->Before = other.Before;
		this->vec_pairs = other.vec_pairs;
		this->deq_pairs = other.deq_pairs;
    }
    return *this;
}

void PmergeMe::insertWithLowerBound_vec(std::vector<int>& main, std::vector<int>& peind)
{
    for (size_t i = 0; i < peind.size(); ++i) 
    {
		if (peind[i] == -1)
            continue;
        std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), peind[i]);
        main.insert(it, peind[i]);
    }
}

void    PmergeMe::MergeInsert_vec(PmergeMe Data)
{		
	double starting = clock(); //TIME START
	for (size_t i = 0; i < Data.Before.size() - 1; i += 2)
	    Data.vec_pairs.push_back(std::make_pair(Data.Before[i], Data.Before[i + 1]));
	if (Data.Before.size() % 2 == 1)
	    Data.vec_pairs.push_back(std::make_pair(Data.Before.back(), -1)); 
	for (size_t i = 0; i < Data.vec_pairs.size(); i++)
	{
		if (Data.vec_pairs[i].first < Data.vec_pairs[i].second)
			std::swap(Data.vec_pairs[i].first , Data.vec_pairs[i].second);
	}
	std::sort(Data.vec_pairs.begin(), Data.vec_pairs.end());
	std::vector<int> ve_main;
	std::vector<int> ve_peind;
	for (size_t i = 0; i < Data.vec_pairs.size(); i++)
	{
		ve_main.push_back(Data.vec_pairs[i].first);
		ve_peind.push_back(Data.vec_pairs[i].second);
	}
	insertWithLowerBound_vec(ve_main, ve_peind);
	double ending = clock(); //END TIME
	double time = ((double)(ending - starting) / CLOCKS_PER_SEC) * 1000000;;
	std::cout << "After : ";
	for (size_t i = 0; i < ve_main.size(); i++)
	{
		std::cout << ve_main[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of elements of " << Data.Before.size() << " elements with std::vector : " << time << " us" << std::endl;
}

void    PmergeMe::MergeInsert_deq(PmergeMe Data)
{		
	double starting = clock();
	for (size_t i = 0; i < Data.Before.size() - 1; i += 2)
	    Data.deq_pairs.push_back(std::make_pair(Data.Before[i], Data.Before[i + 1]));
	if (Data.Before.size() % 2 == 1)
	    Data.deq_pairs.push_back(std::make_pair(Data.Before.back(), -1));
	for (size_t i = 0; i < Data.deq_pairs.size(); i++)
	{
		if (Data.deq_pairs[i].first < Data.deq_pairs[i].second)
			std::swap(Data.deq_pairs[i].first , Data.deq_pairs[i].second);
	}
	std::sort(Data.deq_pairs.begin(), Data.deq_pairs.end());
	std::deque<int> ve_main;
	std::deque<int> ve_peind;
	for (size_t i = 0; i < Data.deq_pairs.size(); i++)
	{
		ve_main.push_back(Data.deq_pairs[i].first);
		ve_peind.push_back(Data.deq_pairs[i].second);
	}
	// ford_jhonson(ve_main);
	insertWithLowerBound_deq(ve_main, ve_peind);
	double ending = clock();
	double time = ((double)(ending - starting) / CLOCKS_PER_SEC) * 1000000;
	std::cout << "Time to process a range of elements of " << Data.Before.size() << " elements with std::deque : " << time << " us" << std::endl;
}

void PmergeMe::insertWithLowerBound_deq(std::deque<int>& main, std::deque<int>& peind)
{
    for (size_t i = 0; i < peind.size(); ++i) 
    {
		if (peind[i] == -1)
            continue;
        std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), peind[i]);
        main.insert(it, peind[i]);
    }
}

void    PmergeMe::print_stack(PmergeMe Data)
{
    std::cout << "Before: ";
	std::vector<int >::iterator it;
    for (it = Data.Before.begin(); it != Data.Before.end(); it++)
        std::cout << *it << " ";
	std::cout << std::endl;
}

void check_for_dup(std::vector<int> vec)
{
	if (vec.size() < 2)
		throw std::runtime_error("Error : Cannot sort one number");
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = (i + 1); j < vec.size() ; j++)
		{
			if (vec[i] == vec[j])
				throw std::runtime_error("Error : check_for_dup numbers.");
		}
	}
}

void    PmergeMe::parsing(int ac, char **av)
{
            std::string str;
	        for (int i = 1; i < ac; i++)
	        {
	        	str += av[i];
	        	if (i < ac - 1)
	        		str += " ";
	        }
            std::istringstream values(str.c_str());
            std::string	Value_readed;
            unsigned long long number;
	        while (values >> Value_readed) //Readin from the big string stream to check short stream
	        {
	        	if (Value_readed.find_first_not_of("0123456789") != std::string::npos || Value_readed.length() > 10) 
	        		throw std::runtime_error("Ivalid input: Only integers possible");
	        	number = std::stoll(Value_readed.c_str());
	        	if (number >= 0 && number <= 2147483647)
	        		this->Before.push_back(number); //Push to before
	        	else
	        		throw std::runtime_error("Error.");
	        }
            check_for_dup(this->Before);
}

PmergeMe::~PmergeMe(){}


// void PmergeMe::ford_jhonson(std::deque<int> ve_main) 
// {
//     int size = ve_main.size();
//     if (size <= 1) {
//         return;
//     } 
//     else 
//     {
//         int mid = size / 2;
//         std::deque<int> left(ve_main.begin(), ve_main.begin() + mid);
//         std::deque<int> right(ve_main.begin() + mid, ve_main.end());

//         ford_jhonson(left);
//         ford_jhonson(right);
        
//         sortPlaces(left, right, ve_main);
//     }
// }


// void PmergeMe::sortPlaces(const std::deque<int> &left, const std::deque<int> &right, std::deque<int> &arr)
// {
//     int i = 0, j = 0, k = 0;
//     int n1 = left.size();
//     int n2 = right.size();
//     while (i < n1 && j < n2) 
//     {
//         if (left[i] <= right[j])
//             arr[k++] = left[i++];
//         else
//             arr[k++] = right[j++];
//     }
//     while (i < n1)
//         arr[k++] = left[i++];
//     while (j < n2)
//         arr[k++] = right[j++];
// }