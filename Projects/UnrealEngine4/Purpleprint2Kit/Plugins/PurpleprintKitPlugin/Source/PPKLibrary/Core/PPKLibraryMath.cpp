/*
===========================================================================
This code is part of the "Source Code" content in
Purpleprint 2 - Kit by David Palacios (Hevedy) <https://github.com/Hevedy>
<https://github.com/Hevedy/PurpleprintKit>

The MIT License (MIT)
Copyright (c) 2014-2016 David Palacios (Hevedy) <https://github.com/Hevedy>
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
===========================================================================
*/

/*
================================================
PPKLibraryMath.cpp
================================================
*/


#include "PPKLibraryPrivatePCH.h"
#include "PPKLibraryMath.h"

#include <chrono>
#include <random>


std::random_device rd;
unsigned gseed = std::chrono::system_clock::now().time_since_epoch().count();

void UPPKLibraryMath::BuildRandom() {
	gseed = std::chrono::system_clock::now().time_since_epoch().count();

	if ( rd.entropy() == 0 ) {
		CreateRandomSeed( gseed );
	} else {
		CreateRandomSeed( rd() );
	}
}

void UPPKLibraryMath::CreateRandomSeed( int32 Seed ) {
	gseed = Seed;
}

void UPPKLibraryMath::UpdateRandomSeedTime() {
	gseed = std::chrono::system_clock::now().time_since_epoch().count();
}

//TODO add the 2 random types Uniform and Default get functions Bool/Int/Float/Vector2D/Vector/Vector4

//void UPPKLibraryMath::GetRandomInteger() {
//
//}


int32 UPPKLibraryMath::IntCount( const int32 IntValue ) {
	//return IntValue == 0 ? 1 : FMath::FloorToInt( log10( FMath::Abs( IntValue ) ) ) + 1;
	FString numValue = FString::FromInt( IntValue );
	return numValue.Len();
}

int32 UPPKLibraryMath::FloatCount( const float FloatValue ) {
	//return IntValue == 0 ? 1 : FMath::FloorToInt( log10( FMath::Abs( IntValue ) ) ) + 1;
	FString numValue = FString::SanitizeFloat( FloatValue );
	return numValue.Len() - 1;
}

float UPPKLibraryMath::MakeFloatFromInts( const int32 A, int32 B ) {
	float value = A;
	int32 m = 1;
	for ( int32 i = 0; i <= IntCount( B ); ++i ) { m *= 10; }
	return value + ( B / m );
}

int32 UPPKLibraryMath::DivideFloatIntoInts( const float Ref, int32 B ) {
	B = FMath::Frac( Ref );
	return FMath::TruncToInt( Ref );
}

float UPPKLibraryMath::InvertFloat( const float FloatValue ) {
	int32 a = FMath::TruncToInt( FloatValue );
	int32 b = FMath::Frac( FloatValue );
	int32 m = 1;
	for ( int32 i = 0; i <= IntCount( FloatValue ); ++i ) { m *= 10; }
	return b + ( a / m );
}

FVector2D UPPKLibraryMath::FloatSplitToVector2D( const float FloatValue ) {
	return FVector2D( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ) );
}

FVector UPPKLibraryMath::FloatSplitToVector( const float FloatValue ) {
	return FVector( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ), 0.0f );
}

FVector4 UPPKLibraryMath::FloatSplitToVector4( const float FloatValue ) {
	return FVector4( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ), 0.0f, 0.0f );
}

FVector2D UPPKLibraryMath::VectorToVector2D( const FVector &VectorValue ) {
	return FVector2D( VectorValue.X, VectorValue.Y );
}

FVector2D UPPKLibraryMath::Vector4ToVector2D( const FVector4 &Vector4Value ) {
	return FVector2D( Vector4Value.X, Vector4Value.Y );
}

FVector UPPKLibraryMath::Vector2DToVector( const FVector2D &Vector2DValue ) {
	return FVector( Vector2DValue.X, Vector2DValue.Y, 0.0f );
}

FVector UPPKLibraryMath::Vector4ToVector( const FVector4 &Vector4Value ) {
	return FVector( Vector4Value.X, Vector4Value.Y, Vector4Value.Z );
}

FVector4 UPPKLibraryMath::Vector2DToVector4( const FVector2D &Vector2DValue ) {
	return FVector4( Vector2DValue.X, Vector2DValue.Y, 0.0f, 0.0f );
}

FVector4 UPPKLibraryMath::VectorToVector4( const FVector &VectorValue ) {
	return FVector4( VectorValue.X, VectorValue.Y, VectorValue.Z, 0.0f );
}

int32 UPPKLibraryMath::IMakeFullFromHalfRot( const int32 intValue ) {
	return intValue < 0 ? intValue + 360 : intValue;
}

float UPPKLibraryMath::FMakeFullFromHalfRot( const float floatValue ) {
	return floatValue < 0.0f ? floatValue + 360.0f : floatValue;
}

int32 UPPKLibraryMath::ICMakeHalfFromFullRot( const int32 intValue ) {
	return intValue > 180 ? intValue - 360 : intValue;
}

float UPPKLibraryMath::FMakeHalfFromFullRot( const float floatValue ) {
	return floatValue > 180.0f ? floatValue - 360.0f : floatValue;
}

FRotator UPPKLibraryMath::MakeFullFromHalfRot( const FRotator rotationValue ) {
	FRotator value;
	value.Roll = rotationValue.Roll < 0.0f ? rotationValue.Roll + 360.0f : rotationValue.Roll;
	value.Pitch = rotationValue.Pitch < 0.0f ? rotationValue.Pitch + 360.0f : rotationValue.Pitch;
	value.Yaw = rotationValue.Yaw < 0.0f ? rotationValue.Yaw + 360.0f : rotationValue.Yaw;
	return value;
}

FRotator UPPKLibraryMath::MakeHalfFromFullRot( const FRotator rotationValue ) {
	FRotator value;
	value.Roll = rotationValue.Roll > 180.0f ? rotationValue.Roll - 360.0f : rotationValue.Roll;
	value.Pitch = rotationValue.Pitch > 180.0f ? rotationValue.Pitch - 360.0f : rotationValue.Pitch;
	value.Yaw = rotationValue.Yaw > 180.0f ? rotationValue.Yaw - 360.0f : rotationValue.Yaw;
	return value;
}

FVector2D UPPKLibraryMath::V2DMakeFullFromHalfRot( const FVector2D vector2DValue ) {
	FVector2D value;
	value.X = vector2DValue.X < 0.0f ? vector2DValue.X + 360.0f : vector2DValue.X;
	value.Y = vector2DValue.Y < 0.0f ? vector2DValue.Y + 360.0f : vector2DValue.Y;
	return value;
}

FVector2D UPPKLibraryMath::V2DMakeHalfFromFullRot( const FVector2D vector2DValue ) {
	FVector2D value;
	value.X = vector2DValue.X > 180.0f ? vector2DValue.X - 360.0f : vector2DValue.X;
	value.Y = vector2DValue.Y > 180.0f ? vector2DValue.Y - 360.0f : vector2DValue.Y;
	return value;
}

FVector UPPKLibraryMath::VMakeFullFromHalfRot( const FVector vectorValue ) {
	FVector value;
	value.X = vectorValue.X < 0.0f ? vectorValue.X + 360.0f : vectorValue.X;
	value.Y = vectorValue.Y < 0.0f ? vectorValue.Y + 360.0f : vectorValue.Y;
	value.Z = vectorValue.Z < 0.0f ? vectorValue.Z + 360.0f : vectorValue.Z;
	return value;
}

FVector UPPKLibraryMath::VMakeHalfFromFullRot( const FVector vectorValue ) {
	FVector value;
	value.X = vectorValue.X > 180.0f ? vectorValue.X - 360.0f : vectorValue.X;
	value.Y = vectorValue.Y > 180.0f ? vectorValue.Y - 360.0f : vectorValue.Y;
	value.Z = vectorValue.Z > 180.0f ? vectorValue.Z - 360.0f : vectorValue.Z;
	return value;
}

FVector4 UPPKLibraryMath::V4MakeFullFromHalfRot( const FVector4 vector4Value ) {
	FVector4 value;
	value.X = vector4Value.X < 0.0f ? vector4Value.X + 360.0f : vector4Value.X;
	value.Y = vector4Value.Y < 0.0f ? vector4Value.Y + 360.0f : vector4Value.Y;
	value.Z = vector4Value.Z < 0.0f ? vector4Value.Z + 360.0f : vector4Value.Z;
	value.W = vector4Value.W < 0.0f ? vector4Value.W + 360.0f : vector4Value.W;
	return value;
}

FVector4 UPPKLibraryMath::V4MakeHalfFromFullRot( const FVector4 vector4Value ) {
	FVector4 value;
	value.X = vector4Value.X > 180.0f ? vector4Value.X - 360.0f : vector4Value.X;
	value.Y = vector4Value.Y > 180.0f ? vector4Value.Y - 360.0f : vector4Value.Y;
	value.Z = vector4Value.Z > 180.0f ? vector4Value.Z - 360.0f : vector4Value.Z;
	value.W = vector4Value.W > 180.0f ? vector4Value.W - 360.0f : vector4Value.W;
	return value;
}

FRotator UPPKLibraryMath::RotatorOrderInvert( const FRotator &rotatorValue ) {
	return FRotator( rotatorValue.Roll, rotatorValue.Yaw, rotatorValue.Pitch );
}

FVector2D UPPKLibraryMath::Vector2DOrderInvert( const FVector2D &vector2DValue ) {
	return FVector2D( vector2DValue.Y, vector2DValue.X );
}

FVector UPPKLibraryMath::VectorOrderInvert( const FVector &vectorValue ) {
	return FVector( vectorValue.Z, vectorValue.Y, vectorValue.X );
}

FVector4 UPPKLibraryMath::Vector4OrderInvert( const FVector4 &vector4Value ) {
	return FVector4( vector4Value.W, vector4Value.Z, vector4Value.Y, vector4Value.X );
}

FRotator UPPKLibraryMath::RotatorOrderRight( const FRotator &rotatorValue ) {
	return FRotator( rotatorValue.Roll, rotatorValue.Pitch, rotatorValue.Yaw );
}

FVector UPPKLibraryMath::VectorOrderRight( const FVector &vectorValue ) {
	return FVector( vectorValue.Z, vectorValue.X, vectorValue.Y );
}

FVector4 UPPKLibraryMath::Vector4OrderRight( const FVector4 &vector4Value ) {
	return FVector4( vector4Value.W, vector4Value.X, vector4Value.Y, vector4Value.Z );
}

FRotator UPPKLibraryMath::RotatorOrderLeft( const FRotator &rotatorValue ) {
	return FRotator( rotatorValue.Yaw, rotatorValue.Roll, rotatorValue.Pitch );
}

FVector UPPKLibraryMath::VectorOrderLeft( const FVector &vectorValue ) {
	return FVector( vectorValue.Y, vectorValue.Z, vectorValue.X );
}

FVector4 UPPKLibraryMath::Vector4OrderLeft( const FVector4 &vector4Value ) {
	return FVector4( vector4Value.Y, vector4Value.Z, vector4Value.W, vector4Value.X );
}

bool UPPKLibraryMath::GetConfigBool( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return false;

	bool value = false;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetBool( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetBool( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetBool( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetBool( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetBool( *sectionName, *variableName, value, GEngineIni );
	}
	return value;
}

int32 UPPKLibraryMath::GetConfigInt( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return 0;

	int32 value = 0;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetInt( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetInt( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetInt( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetInt( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetInt( *sectionName, *variableName, value, GEngineIni );
	}
	return value;
}

float UPPKLibraryMath::GetConfigFloat( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return 0;

	float value = 0.0f;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetFloat( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetFloat( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetFloat( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetFloat( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetFloat( *sectionName, *variableName, value, GEngineIni );
	}
	return value;
}

FVector UPPKLibraryMath::GetConfigVector( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return FVector::ZeroVector;

	FVector value = FVector::ZeroVector;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetVector( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetVector( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetVector( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetVector( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetVector( *sectionName, *variableName, value, GEngineIni );
	}
	return value;
}

FRotator UPPKLibraryMath::GetConfigRotator( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return FRotator::ZeroRotator;

	FRotator value = FRotator::ZeroRotator;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetRotator( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetRotator( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetRotator( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetRotator( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetRotator( *sectionName, *variableName, value, GEngineIni );
	}
	return value;
}

FLinearColor UPPKLibraryMath::GetConfigColor( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return FColor::Black;

	FColor value = FColor::Black;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetColor( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetColor( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetColor( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetColor( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetColor( *sectionName, *variableName, value, GEngineIni );
	}
	return FLinearColor( value );
}

FString UPPKLibraryMath::GetConfigString( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return "";

	FString value = "";
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetString( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetString( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetString( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetString( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetString( *sectionName, *variableName, value, GEngineIni );
	}
	return value;
}

FVector2D UPPKLibraryMath::GetConfigVector2D( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
	if ( !GConfig ) return FVector2D::ZeroVector;

	FVector2D value = FVector2D::ZeroVector;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->GetVector2D( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->GetVector2D( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->GetVector2D( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->GetVector2D( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->GetVector2D( *sectionName, *variableName, value, GEngineIni );
	}
	return FVector2D( value.X, value.Y );
}

void UPPKLibraryMath::SetConfigBool( const FString sectionName, const FString variableName, const bool value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;
	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetBool( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetBool( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetBool( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetBool( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetBool( *sectionName, *variableName, value, GEngineIni );
	}

}

void UPPKLibraryMath::SetConfigInt( const FString sectionName, const FString variableName, const int32 value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;

	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetInt( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetInt( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetInt( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetInt( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetInt( *sectionName, *variableName, value, GEngineIni );
	}
}

void UPPKLibraryMath::SetConfigFloat( const FString sectionName, const FString variableName, const float value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;

	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetFloat( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetFloat( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetFloat( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetFloat( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetFloat( *sectionName, *variableName, value, GEngineIni );
	}
}

void UPPKLibraryMath::SetConfigVector( const FString sectionName, const FString variableName, const FVector value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;

	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetVector( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetVector( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetVector( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetVector( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetVector( *sectionName, *variableName, value, GEngineIni );
	}
}

void UPPKLibraryMath::SetConfigRotator( const FString sectionName, const FString variableName, const FRotator value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;

	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetRotator( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetRotator( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetRotator( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetRotator( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetRotator( *sectionName, *variableName, value, GEngineIni );
	}
}

void UPPKLibraryMath::SetConfigColor( const FString sectionName, const FString variableName, const FLinearColor value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;

	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetColor( *sectionName, *variableName, value.ToFColor( true ), GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetColor( *sectionName, *variableName, value.ToFColor( true ), GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetColor( *sectionName, *variableName, value.ToFColor( true ), GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetColor( *sectionName, *variableName, value.ToFColor( true ), GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetColor( *sectionName, *variableName, value.ToFColor( true ), GEngineIni );
	}
}

void UPPKLibraryMath::SetConfigString( const FString sectionName, const FString variableName, const FString value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;

	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetString( *sectionName, *variableName, *value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetString( *sectionName, *variableName, *value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetString( *sectionName, *variableName, *value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetString( *sectionName, *variableName, *value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetString( *sectionName, *variableName, *value, GEngineIni );
	}
}

void UPPKLibraryMath::SetConfigVector2D( const FString sectionName, const FString variableName, const FVector2D value, const EIniFilesList iniFile ) {
	if ( !GConfig ) return;

	switch ( iniFile ) {
		case EIniFilesList::GGameIni:
			GConfig->SetVector2D( *sectionName, *variableName, value, GGameIni );
		case EIniFilesList::GGameUserSettingsIni:
			GConfig->SetVector2D( *sectionName, *variableName, value, GGameUserSettingsIni );
		case EIniFilesList::GScalabilityIni:
			GConfig->SetVector2D( *sectionName, *variableName, value, GScalabilityIni );
		case EIniFilesList::GInputIni:
			GConfig->SetVector2D( *sectionName, *variableName, value, GInputIni );
		case EIniFilesList::GEngineIni:
			GConfig->SetVector2D( *sectionName, *variableName, value, GEngineIni );
	}
}

uint8 UPPKLibraryMath::BMin( uint8 A, uint8 B ) {
	return FMath::Min<uint8>( A, B );
}

uint8 UPPKLibraryMath::BMax( uint8 A, uint8 B ) {
	return FMath::Max<uint8>( A, B );
}

uint8 UPPKLibraryMath::BGetCloser( uint8 Ref, uint8 A, uint8 B ) {
	return Closer<uint8>( Ref, A, B );
}

uint8 UPPKLibraryMath::BGetFurther( uint8 Ref, uint8 A, uint8 B ) {
	return Further<uint8>( Ref, A, B );
}

int32 UPPKLibraryMath::IGetCloser( int32 Ref, int32 A, int32 B ) {
	return Closer<int32>( Ref, A, B );
}

int32 UPPKLibraryMath::IGetFurther( int32 Ref, int32 A, int32 B ) {
	return Further<int32>( Ref, A, B );
}

float UPPKLibraryMath::FGetCloser( float Ref, float A, float B ) {
	return Closer<float>( Ref, A, B );
}

float UPPKLibraryMath::FGetFurther( float Ref, float A, float B ) {
	return Further<float>( Ref, A, B );
}

void UPPKLibraryMath::CloserIntArray( const int32 IntRefValue, const TArray<int32>& IntArray, const bool NotEqual, int32& IndexOfCloserValue, int32& CloserValue ) {
	CloserValue = Closer<int32>( IntRefValue, IntArray, NotEqual, &IndexOfCloserValue );
}

void UPPKLibraryMath::FurtherIntArray( const int32 IntRefValue, const TArray<int32>& IntArray, int32& IndexOfFurtherValue, int32& FurtherValue ) {
	FurtherValue = Further<int32>( IntRefValue, IntArray, &IndexOfFurtherValue );
}

void UPPKLibraryMath::CloserFloatArray( const float FloatRefValue, const TArray<float>& FloatArray, const bool NotEqual, int32& IndexOfCloserValue, float& CloserValue ) {
	CloserValue = Closer<float>( FloatRefValue, FloatArray, NotEqual, &IndexOfCloserValue );
}

void UPPKLibraryMath::FurtherFloatArray( const float FloatRefValue, const TArray<float>& FloatArray, int32& IndexOfFurtherValue, float& FurtherValue ) {
	FurtherValue = Further<float>( FloatRefValue, FloatArray, &IndexOfFurtherValue );
}

void UPPKLibraryMath::CloserByteArray( const uint8 ByteRefValue, const TArray<uint8>& ByteArray, const bool NotEqual, int32& IndexOfCloserValue, uint8& CloserValue ) {
	CloserValue = Closer<uint8>( ByteRefValue, ByteArray, NotEqual, &IndexOfCloserValue );
}

void UPPKLibraryMath::FurtherByteArray( const uint8 ByteRefValue, const TArray<uint8>& ByteArray, int32& IndexOfFurtherValue, uint8& FurtherValue ) {
	FurtherValue = Further<uint8>( ByteRefValue, ByteArray, &IndexOfFurtherValue );
}
