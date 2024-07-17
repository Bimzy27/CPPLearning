#pragma once
#include <raylib.h>
#include <math.h>

Vector2 operator+(const Vector2& lhs, const Vector2& rhs) 
{
	Vector2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;
	return result;
}

Vector2 operator-(const Vector2& lhs, const Vector2& rhs) 
{
	Vector2 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;
	return result;
}

Vector2 operator*(const Vector2& lhs, const Vector2& rhs) 
{
	Vector2 result;
	result.x = lhs.x * rhs.x;
	result.y = lhs.y * rhs.y;
	return result;
}

Vector2 operator*(const Vector2& lhs, const float& rhs) 
{
	Vector2 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;
	return result;
}

float Magnitude(const Vector2& vector) 
{
	// Calculate the magnitude
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

float Distance(const Vector2& lhs, const Vector2& rhs) 
{
	return Magnitude(lhs - rhs);
}

Vector2 Normalize(const Vector2& vector) 
{
	// Calculate the magnitude
	float magnitude = Magnitude(vector);

	// Handle zero magnitude to avoid division by zero
	if (magnitude > 0.0f){
		// Normalize the vector components
		Vector2 normalizedVector;
		normalizedVector.x = vector.x / magnitude;
		normalizedVector.y = vector.y / magnitude;
		return normalizedVector;
	}
	else {
		// Return the original vector if magnitude is zero
		return vector;
	}
}