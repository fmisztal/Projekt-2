#pragma once
#include "smartphone.h"

Smartphone::Smartphone(const int inches, const int weight, const int megapiksels)
{
    m_inches=inches;
    m_weight=weight;
    m_megapiksels=megapiksels;
}

int Smartphone::inches()
{
    return m_inches;
}

void Smartphone::setInches(int inches)
{
    m_inches = inches;
}

int Smartphone::weight()
{
    return m_weight;
}

void Smartphone::setWeight(int weight)
{
    m_weight = weight;
}

int Smartphone::megapiksels()
{
    return m_megapiksels;
}

void Smartphone::setMegapiksels(int megapiksels)
{
    m_megapiksels = megapiksels;
}

