#ifndef SDK_MATH_MATRIX4X4
#define SDK_MATH_MATRIX4X4

struct Matrix4x4 {
	float matrix[4][4];

	Matrix4x4() { }
	Matrix4x4(
		float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33)
	{
		matrix[0][0] = m00;
		matrix[0][1] = m01;
		matrix[0][2] = m02;
		matrix[0][3] = m03;
		matrix[1][0] = m10;
		matrix[1][1] = m11;
		matrix[1][2] = m12;
		matrix[1][3] = m13;
		matrix[2][0] = m20;
		matrix[2][1] = m21;
		matrix[2][2] = m22;
		matrix[2][3] = m23;
		matrix[3][0] = m30;
		matrix[3][1] = m31;
		matrix[3][2] = m32;
		matrix[3][3] = m33;
	}

	inline float* operator[](int i)
	{
		return matrix[i];
	}
	inline float* Base()
	{
		return &matrix[0][0];
	}
};

#endif
