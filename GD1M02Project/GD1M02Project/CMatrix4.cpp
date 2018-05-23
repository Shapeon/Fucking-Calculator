#include "CMatrix4.h"



CMatrix4::CMatrix4()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->SetElement(i, j, 0);
		}
	}
}


CMatrix4::~CMatrix4()
{
}

void CMatrix4::SetElement(int _iX, int _iY, float _fValue)
{
	//Sets value of specified position in Matrix
	m_fMatrix[_iX][_iY] = _fValue;
}

float CMatrix4::GetElement(int _iX, int _iY) const
{
	float desired_value = m_fMatrix[_iX][_iY];
	return desired_value;
}

CMatrix4 & CMatrix4::Identity(CMatrix4 & _rResult)
{
	//Creates an Identity Matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				_rResult.SetElement(i, j, 1);
			}
			else {
				_rResult.SetElement(i, j, 0);
			}
		}
	}
	return _rResult;
}

/*CMatrix4 & CMatrix4::Zero(CMatrix4 & _rResult)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_rResult.SetElement(i, j, 0);
		}
	}
	return _rResult;
}*/

/*bool CMatrix4::Equals(const CMatrix4 & _rA, const CMatrix4 & _rB)
{
	return false;
}*/

CMatrix4 & CMatrix4::Add(const CMatrix4 & _rA, const CMatrix4 & _rB, CMatrix4 & _rResult)
{
	//Adds two Matrices of identical sides together
	_rResult.SetElement(0, 0, _rA.GetElement(0, 0) + _rB.GetElement(0, 0));
	_rResult.SetElement(0, 1, _rA.GetElement(0, 1) + _rB.GetElement(0, 1));
	_rResult.SetElement(0, 2, _rA.GetElement(0, 2) + _rB.GetElement(0, 2));
	_rResult.SetElement(0, 3, _rA.GetElement(0, 3) + _rB.GetElement(0, 3));

	_rResult.SetElement(1, 0, _rA.GetElement(1, 0) + _rB.GetElement(1, 0));
	_rResult.SetElement(1, 1, _rA.GetElement(1, 1) + _rB.GetElement(1, 1));
	_rResult.SetElement(1, 2, _rA.GetElement(1, 2) + _rB.GetElement(1, 2));
	_rResult.SetElement(1, 3, _rA.GetElement(1, 3) + _rB.GetElement(1, 3));

	_rResult.SetElement(2, 0, _rA.GetElement(2, 0) + _rB.GetElement(2, 0));
	_rResult.SetElement(2, 1, _rA.GetElement(2, 1) + _rB.GetElement(2, 1));
	_rResult.SetElement(2, 2, _rA.GetElement(2, 2) + _rB.GetElement(2, 2));
	_rResult.SetElement(2, 3, _rA.GetElement(2, 3) + _rB.GetElement(2, 3));

	_rResult.SetElement(3, 0, _rA.GetElement(3, 0) + _rB.GetElement(3, 0));
	_rResult.SetElement(3, 1, _rA.GetElement(3, 1) + _rB.GetElement(3, 1));
	_rResult.SetElement(3, 2, _rA.GetElement(3, 2) + _rB.GetElement(3, 2));
	_rResult.SetElement(3, 3, _rA.GetElement(3, 3) + _rB.GetElement(3, 3));

	return _rResult;
}

CMatrix4 & CMatrix4::Subtract(const CMatrix4 & _rA, const CMatrix4 & _rB, CMatrix4 & _rResult)
{
	_rResult.SetElement(0, 0, _rA.GetElement(0, 0) - _rB.GetElement(0, 0));
	_rResult.SetElement(0, 1, _rA.GetElement(0, 1) - _rB.GetElement(0, 1));
	_rResult.SetElement(0, 2, _rA.GetElement(0, 2) - _rB.GetElement(0, 2));
	_rResult.SetElement(0, 3, _rA.GetElement(0, 3) - _rB.GetElement(0, 3));

	_rResult.SetElement(1, 0, _rA.GetElement(1, 0) - _rB.GetElement(1, 0));
	_rResult.SetElement(1, 1, _rA.GetElement(1, 1) - _rB.GetElement(1, 1));
	_rResult.SetElement(1, 2, _rA.GetElement(1, 2) - _rB.GetElement(1, 2));
	_rResult.SetElement(1, 3, _rA.GetElement(1, 3) - _rB.GetElement(1, 3));

	_rResult.SetElement(2, 0, _rA.GetElement(2, 0) - _rB.GetElement(2, 0));
	_rResult.SetElement(2, 1, _rA.GetElement(2, 1) - _rB.GetElement(2, 1));
	_rResult.SetElement(2, 2, _rA.GetElement(2, 2) - _rB.GetElement(2, 2));
	_rResult.SetElement(2, 3, _rA.GetElement(2, 3) - _rB.GetElement(2, 3));

	_rResult.SetElement(3, 0, _rA.GetElement(3, 0) - _rB.GetElement(3, 0));
	_rResult.SetElement(3, 1, _rA.GetElement(3, 1) - _rB.GetElement(3, 1));
	_rResult.SetElement(3, 2, _rA.GetElement(3, 2) - _rB.GetElement(3, 2));
	_rResult.SetElement(3, 3, _rA.GetElement(3, 3) - _rB.GetElement(3, 3));

	return _rResult;
}

CMatrix4 & CMatrix4::Multiply(float _fScalar, const CMatrix4 & _rA, CMatrix4 & _rResult)
{
	_rResult.SetElement(0, 0, _rA.GetElement(0, 0) * _fScalar);
	_rResult.SetElement(0, 1, _rA.GetElement(0, 1) * _fScalar);
	_rResult.SetElement(0, 2, _rA.GetElement(0, 2) * _fScalar);
	_rResult.SetElement(0, 3, _rA.GetElement(0, 3) * _fScalar);

	_rResult.SetElement(1, 0, _rA.GetElement(1, 0) * _fScalar);
	_rResult.SetElement(1, 1, _rA.GetElement(1, 1) * _fScalar);
	_rResult.SetElement(1, 2, _rA.GetElement(1, 2) * _fScalar);
	_rResult.SetElement(1, 3, _rA.GetElement(1, 3) * _fScalar);

	_rResult.SetElement(2, 0, _rA.GetElement(2, 0) * _fScalar);
	_rResult.SetElement(2, 1, _rA.GetElement(2, 1) * _fScalar);
	_rResult.SetElement(2, 2, _rA.GetElement(2, 2) * _fScalar);
	_rResult.SetElement(2, 3, _rA.GetElement(2, 3) * _fScalar);

	_rResult.SetElement(3, 0, _rA.GetElement(3, 0) * _fScalar);
	_rResult.SetElement(3, 1, _rA.GetElement(3, 1) * _fScalar);
	_rResult.SetElement(3, 2, _rA.GetElement(3, 2) * _fScalar);
	_rResult.SetElement(3, 3, _rA.GetElement(3, 3) * _fScalar);

	return _rResult;
}

/*CMatrix4 & CMatrix4::Multiply(const CMatrix4 & _rA, const CMatrix4 & _rB, CMatrix4 & _rResult)
{
	//First Row
	_rResult.SetElement(0, 0, ((_rA.GetElement(0, 0) * _rB.GetElement(0, 0)) + (_rA.GetElement(0, 1) * _rB.GetElement(1, 0)) + (_rA.GetElement(0, 2) * _rB.GetElement(2, 0))));
	_rResult.SetElement(0, 1, (_rA.GetElement(0, 0) * _rB.GetElement(0, 1)) + (_rA.GetElement(0, 1) * _rB.GetElement(1, 1)) + (_rA.GetElement(0, 2) * _rB.GetElement(2, 1)));
	_rResult.SetElement(0, 2, ((_rA.GetElement(0, 0) * _rB.GetElement(0, 2)) + (_rA.GetElement(0, 1) * _rB.GetElement(1, 2)) + (_rA.GetElement(0, 2) * _rB.GetElement(2, 2))));
	_rResult.SetElement(0, 3, ((_rA.GetElement(0, 0) * _rB.GetElement(0, 3)) + (_rA.GetElement(0, 1) * _rB.GetElement(1, 3)) + (_rA.GetElement(0, 2) * _rB.GetElement(2, 3))));

	//Second Row			  
	_rResult.SetElement(1, 0, ((_rA.GetElement(1, 0) * _rB.GetElement(0, 0)) + (_rA.GetElement(1, 1) * _rB.GetElement(1, 0)) + (_rA.GetElement(1, 2) * _rB.GetElement(2, 0))));
	_rResult.SetElement(1, 1, ((_rA.GetElement(1, 0) * _rB.GetElement(0, 1)) + (_rA.GetElement(1, 1) * _rB.GetElement(1, 1)) + (_rA.GetElement(1, 2) * _rB.GetElement(2, 1))));
	_rResult.SetElement(1, 2, ((_rA.GetElement(1, 0) * _rB.GetElement(0, 2)) + (_rA.GetElement(1, 1) * _rB.GetElement(1, 2)) + (_rA.GetElement(1, 2) * _rB.GetElement(2, 2))));

	//Third Row
	_rResult.SetElement(2, 0, ((_rA.GetElement(2, 0) * _rB.GetElement(0, 0)) + (_rA.GetElement(2, 1) * _rB.GetElement(1, 0)) + (_rA.GetElement(2, 2) * _rB.GetElement(2, 0))));
	_rResult.SetElement(2, 1, ((_rA.GetElement(2, 0) * _rB.GetElement(0, 1)) + (_rA.GetElement(2, 1) * _rB.GetElement(1, 1)) + (_rA.GetElement(2, 2) * _rB.GetElement(2, 1))));
	_rResult.SetElement(2, 2, ((_rA.GetElement(2, 0) * _rB.GetElement(0, 2)) + (_rA.GetElement(2, 1) * _rB.GetElement(1, 2)) + (_rA.GetElement(2, 2) * _rB.GetElement(2, 2))));
}

CMatrix4 & CMatrix4::Transpose(const CMatrix4 & _rA, CMatrix4 & _rResult)
{
	// TODO: insert return statement here
}

float CMatrix4::Determinant(const CMatrix4 & _rA)
{
	return 0.0f;
}

bool CMatrix4::Inverse(const CMatrix4 & _rA, CMatrix4 & _rResult)
{
	return false;
}
*/