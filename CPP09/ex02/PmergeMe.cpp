/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migupere <migupere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:28:38 by migupere          #+#    #+#             */
/*   Updated: 2025/03/30 16:15:32 by migupere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(char **input) {
	checkInput(input);
	print(input);
}
PmergeMe::PmergeMe(const PmergeMe &other) {*this = other;}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {(void)other; return *this;}
PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
    std::vector<size_t> sequence;
    sequence.push_back(0); // Começa com 0 (facilita implementação)
    sequence.push_back(1); // Segundo número é 1
    
    size_t i = 2;
    while (sequence[i-1] < n) {
        sequence.push_back(sequence[i-1] + 2 * sequence[i-2]);
        i++;
    }
    return sequence;
}


std::vector<size_t> PmergeMe::expandJacobsthalIndices(size_t n) {
    if (n <= 1) return std::vector<size_t>();
        
        std::vector<size_t> jacobsthal = generateJacobsthalSequence(n);
        std::vector<size_t> indices;
        std::vector<bool> used(n, false);
        
        // Começamos com 1 como o primeiro índice
        if (n > 0) {
            indices.push_back(0);
            used[0] = true;
        }
        
        // Para cada número na sequência de Jacobsthal
        for (size_t i = 2; i < jacobsthal.size() && jacobsthal[i] < n; ++i) {
            // Adicionar o índice de Jacobsthal se ainda não usado
            size_t jIdx = jacobsthal[i];
            if (jIdx < n && !used[jIdx]) {
                indices.push_back(jIdx);
                used[jIdx] = true;
            }
            
            // Adicionar índices intermediários em ordem decrescente
            for (size_t j = jIdx; j > jacobsthal[i-1]; --j) {
                if (j < n && !used[j]) {
                    indices.push_back(j);
                    used[j] = true;
                }
            }
        }
        
        // Adicionar quaisquer índices restantes em ordem
        for (size_t i = 0; i < n; ++i) {
            if (!used[i]) {
                indices.push_back(i);
            }
        }
        
        return indices;
}

template <typename T>
void PmergeMe::FordJohnson(T &c) {
    if (c.size() <= 1) return; // Caso base da recursão
        
    // Fase 1: Emparelhar elementos e separar em maiores e menores
    T mainChain; // Cadeia principal com os maiores de cada par
    T pend; // Elementos pendentes (menores de cada par)
    
    // Elemento solitário (se o tamanho for ímpar)
    typename T::value_type oddElement;
    bool hasOddElement = false;
    
    if (c.size() % 2 != 0) {
        hasOddElement = true;
        oddElement = c[c.size() - 1];
        c.pop_back();
    }
    
    // Formar pares e separar
    for (size_t i = 0; i < c.size(); i += 2) {
        if (c[i] > c[i + 1]) {
            mainChain.push_back(c[i]);
            pend.push_back(c[i + 1]);
        } else {
            mainChain.push_back(c[i + 1]);
            pend.push_back(c[i]);
        }
    }
    
    // Fase 2: Ordenar recursivamente a cadeia principal
    FordJohnson(mainChain);
    
    // Fase 3: Reconstrói c com a cadeia principal ordenada
    c.clear();
    c = mainChain;
    
    // Fase 4: Inserir os elementos pendentes
    // Primeiro elemento (sempre o primeiro pendente)
    if (!pend.empty()) {
        typename T::iterator pos = std::lower_bound(c.begin(), c.end(), pend[0]);
        c.insert(pos, pend[0]);
    }
    
    // Calcular ordem de inserção baseada na sequência de Jacobsthal
    if (pend.size() > 1) {
        std::vector<size_t> insertOrder = expandJacobsthalIndices(pend.size());
        
        // Começar do segundo índice pois o primeiro já foi inserido
        for (size_t i = 1; i < insertOrder.size(); ++i) {
            size_t idx = insertOrder[i];
            if (idx < pend.size()) {
                typename T::iterator pos = std::lower_bound(c.begin(), c.end(), pend[idx]);
                c.insert(pos, pend[idx]);
            }
        }
    }
    
    // Inserir o elemento solitário, se existir
    if (hasOddElement) {
        typename T::iterator pos = std::lower_bound(c.begin(), c.end(), oddElement);
        c.insert(pos, oddElement);
    }
}

void PmergeMe::checkInput(char **av) {
    int i = 1;
    while (av[i]) {
        std::string str(av[i]);
        for (size_t j = 0; j < str.size(); j++) {
            if (!isdigit(str[j])) {
                throw std::invalid_argument("Invalid input");
            }
        }
        long num = std::strtol(str.c_str(), NULL, 10);
        if (num > std::numeric_limits<int>::max() || num <= 0) {
            throw std::invalid_argument("Invalid input");
        }
        _vec.push_back(static_cast<int>(num));
        _deq.push_back(static_cast<int>(num));
        i++;
    }
}

void PmergeMe::print(char **input) {
    std::cout << "Before: ";
    int i = 1;
    while (input[i]) {
        std::cout << input[i];
        if (input[i + 1])
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;

    clock_t vecstart = clock();
    FordJohnson(_vec);
    clock_t vecend = clock();
    
    clock_t deqstart = clock();
    FordJohnson(_deq);
    clock_t deqend = clock();
    
    double vecduration = static_cast<double>(vecend - vecstart) * 1e6 / CLOCKS_PER_SEC;
    double deqduration = static_cast<double>(deqend - deqstart) * 1e6 / CLOCKS_PER_SEC;

    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size(); i++) {
        std::cout << _vec[i];
        if (i + 1 < _vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Time to process a range of " << _vec.size()
        << " elements with std::vector : " << vecduration << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
        << " elements with std::deque : " << deqduration << " us" << std::endl;
}

