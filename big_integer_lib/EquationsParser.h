#pragma once

#include "BigInteger.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <iterator>
#include <utility>

using namespace std;

class Exp {
public:
    Exp() = default;
    virtual ~Exp() = default;
    virtual BigInteger evaluate() = 0;
    virtual void print() = 0;
    virtual void release() = 0;
};

class Term: public Exp {
private:
    BigInteger val;
public:
    explicit Term(string &v) {
        v.erase(remove_if(v.begin(), v.end(), ::isspace), v.end());
        val = BigInteger(v);
    }

    BigInteger evaluate() override {
        return val;
    }
    void print() override {
        cout << ' ' << val << ' ';
    }
    void release() override {}
};

class Node: public Exp {
private:
    Exp *l_exp;
    Exp *r_exp;
    char op; // +, -, *, /
public:
    Node(char op, Exp* left, Exp* right) : op(op), l_exp(left), r_exp(right) {}
    ~Node() override = default;

    BigInteger evaluate() override;
    void print() override;
    void release() override;
};

Exp* strToExp(string &str);
