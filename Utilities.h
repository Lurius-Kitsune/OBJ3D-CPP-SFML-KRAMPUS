#pragma once
#include "Macro.h"

u_int GetUniqueID();
int GetRandomNumberInRange(const int _min, const int _max);
float DegToRad(const float _degrees);
float RadToDeg(const float _radians);

template <typename Type>
Type GetRandomNumberInRange(const Type& _min, const Type& _max)
{
    random_device _rSeed; // Obtient un graine al�atoire
    mt19937 _gen(_rSeed()); // Initialise le g�n�rateur avec la graine
    uniform_real_distribution<Type> _distr(_min, _max); // D�finit la distribution (les limites)

    return _distr(_gen); // G�n�ration du nombre
}

template <typename Type, typename BaseType, IS_BASE_OF(BaseType, Type)> 
Type* Cast(BaseType* _baseType)
{
    if (!_baseType) return nullptr;
	return dynamic_cast<Type*>(_baseType);
}