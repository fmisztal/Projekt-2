#pragma once
#include "phone.h"
#include "electronic_device.h"

Phone::Phone(string brand, const int processor, const bool dual_sim)
{
    m_brand=brand;
    m_processor=processor;
    m_dual_sim=dual_sim;
}

string Phone::brand() const
{
    return m_brand;
}

void Phone::setBrand(const string &brand)
{
    m_brand = brand;
}

int Phone::processor() const
{
    return m_processor;
}

void Phone::setProcessor(int processor)
{
    m_processor = processor;
}

bool Phone::dual_sim() const
{
    return m_dual_sim;
}

void Phone::setDual_sim(bool dual_sim)
{
    m_dual_sim = dual_sim;
}
