#pragma once
class CMatrix4
{
	
public:
	float m_fMatrix[4][4];

	CMatrix4();
	~CMatrix4();


	// 0 based index.
	void SetElement(int _iX, int _iY, float _fValue);
	float GetElement(int _iX, int _iY) const;

	static CMatrix4& Identity(CMatrix4& _rResult);
	//static CMatrix4& Zero(CMatrix4& _rResult);

	//static bool Equals(const CMatrix4& _rA, const CMatrix4& _rB);
	static CMatrix4& Add(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);
	static CMatrix4& Subtract(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);
	static CMatrix4& Multiply(float _fScalar, const CMatrix4& _rA, CMatrix4& _rResult);
	static CMatrix4& Multiply(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);
	//static CMatrix4& Transpose(const CMatrix4& _rA, CMatrix4& _rResult);
	//static float Determinant(const CMatrix4& _rA);
	//static bool Inverse(const CMatrix4& _rA, CMatrix4& _rResult);
};

