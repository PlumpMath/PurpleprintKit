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
PPKLibraryTools.cpp
================================================
*/


#include "PPKLibraryPrivatePCH.h"
#include "PPKLibraryTools.h"
#include "PPKLibraryMath.h"

#include <chrono>
#include <random>

UPPKLibraryTools::UPPKLibraryTools( const class FObjectInitializer& ObjectInitializer ) {

}



void UPPKLibraryTools::PrintByteArray( const TArray<uint8> ByteArray ) {
	if ( ByteArray.Num() != 0 ) {
		for ( int32 i = 0; i < ByteArray.Num(); i++ ) {
			GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, FString::FromInt( ByteArray[i] ) );
		}
	}
}


void UPPKLibraryTools::PrintIntArray( const TArray<int32> IntArray ) {
	if ( IntArray.Num() != 0 ) {
		for ( int32 i = 0; i < IntArray.Num(); i++ ) {
			GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, FString::FromInt( IntArray[i] ) );
		}
	}
}

void UPPKLibraryTools::PrintFloatArray( const TArray<float> FloatArray ) {
	if ( FloatArray.Num() != 0 ) {
		for ( int32 i = 0; i < FloatArray.Num(); i++ ) {
			GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, FString::SanitizeFloat( FloatArray[i] ) );
		}
	}
}

void UPPKLibraryTools::PrintVector2DArray( const TArray<FVector2D> Vector2DArray ) {
	if ( Vector2DArray.Num() != 0 ) {
		for ( int32 i = 0; i < Vector2DArray.Num(); i++ ) {
			GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, "( " + 
											  FString::SanitizeFloat( Vector2DArray[i].X ) + " , " + 
											  FString::SanitizeFloat( Vector2DArray[i].Y ) + " )" );
		}
	}
}


void UPPKLibraryTools::PrintVectorArray( const TArray<FVector> VectorArray ) {
	if ( VectorArray.Num() != 0 ) {
		for ( int32 i = 0; i < VectorArray.Num(); i++ ) {
			GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, "( " + 
											  FString::SanitizeFloat( VectorArray[i].X ) + " , " + 
											  FString::SanitizeFloat( VectorArray[i].Y ) + " , " + 
											  FString::SanitizeFloat( VectorArray[i].Z ) + " )" );
		}
	}
}


void UPPKLibraryTools::PrintVector4Array( const TArray<FVector4> Vector4Array ) {
	if ( Vector4Array.Num() != 0 ) {
		for ( int32 i = 0; i < Vector4Array.Num(); i++ ) {
			GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, "( " +
											  FString::SanitizeFloat( Vector4Array[i].X ) + " , " +
											  FString::SanitizeFloat( Vector4Array[i].Y ) + " , " +
											  FString::SanitizeFloat( Vector4Array[i].Z ) + " , " +
											  FString::SanitizeFloat( Vector4Array[i].W ) + " )" );
		}
	}
}


void UPPKLibraryTools::PrintRotatorArray( const TArray<FRotator> RotatorArray ) {
	if ( RotatorArray.Num() != 0 ) {
		for ( int32 i = 0; i < RotatorArray.Num(); i++ ) {
			GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, "( " +
											  FString::SanitizeFloat( RotatorArray[i].Pitch ) + " , " +
											  FString::SanitizeFloat( RotatorArray[i].Roll ) + " , " +
											  FString::SanitizeFloat( RotatorArray[i].Yaw ) + " )" );
		}
	}
}

float UPPKLibraryTools::MakeFloatFromInts( const int32 A, const int32 B ) {
	float value = A;
	int32 m = 1;
	for ( int32 i = 0; i <= UPPKLibraryMath::IntCount( B ); ++i ) { m *= 10; }
	return value + ( B / m );
}

int32 UPPKLibraryTools::DivideFloatIntoInts( const float Ref, int32& B ) {
	B = FMath::Frac( Ref );
	return FMath::TruncToInt( Ref );
}

float UPPKLibraryTools::InvertFloat( const float FloatValue ) {
	int32 a = FMath::TruncToInt( FloatValue );
	int32 b = FMath::Frac( FloatValue );
	int32 m = 1;
	for ( int32 i = 0; i <= UPPKLibraryMath::IntCount( FloatValue ); ++i ) { m *= 10; }
	return b + ( a / m );
}

FVector2D UPPKLibraryTools::FloatSplitToVector2D( const float FloatValue ) {
	return FVector2D( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ) );
}

FVector UPPKLibraryTools::FloatSplitToVector( const float FloatValue ) {
	return FVector( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ), 0.0f );
}

FVector4 UPPKLibraryTools::FloatSplitToVector4( const float FloatValue ) {
	return FVector4( FMath::TruncToInt( FloatValue ), FMath::Frac( FloatValue ), 0.0f, 0.0f );
}

FVector2D UPPKLibraryTools::VectorToVector2D( const FVector &VectorValue ) {
	return FVector2D( VectorValue.X, VectorValue.Y );
}

FVector2D UPPKLibraryTools::Vector4ToVector2D( const FVector4 &Vector4Value ) {
	return FVector2D( Vector4Value.X, Vector4Value.Y );
}

FVector UPPKLibraryTools::Vector2DToVector( const FVector2D &Vector2DValue ) {
	return FVector( Vector2DValue.X, Vector2DValue.Y, 0.0f );
}

FVector UPPKLibraryTools::Vector4ToVector( const FVector4 &Vector4Value ) {
	return FVector( Vector4Value.X, Vector4Value.Y, Vector4Value.Z );
}

FVector4 UPPKLibraryTools::Vector2DToVector4( const FVector2D &Vector2DValue ) {
	return FVector4( Vector2DValue.X, Vector2DValue.Y, 0.0f, 0.0f );
}

FVector4 UPPKLibraryTools::VectorToVector4( const FVector &VectorValue ) {
	return FVector4( VectorValue.X, VectorValue.Y, VectorValue.Z, 0.0f );
}

FRotator UPPKLibraryTools::RotatorOrderInvert( const FRotator &rotatorValue ) {
	return FRotator( rotatorValue.Roll, rotatorValue.Yaw, rotatorValue.Pitch );
}

FVector2D UPPKLibraryTools::Vector2DOrderInvert( const FVector2D &vector2DValue ) {
	return FVector2D( vector2DValue.Y, vector2DValue.X );
}

FVector UPPKLibraryTools::VectorOrderInvert( const FVector &vectorValue ) {
	return FVector( vectorValue.Z, vectorValue.Y, vectorValue.X );
}

FVector4 UPPKLibraryTools::Vector4OrderInvert( const FVector4 &vector4Value ) {
	return FVector4( vector4Value.W, vector4Value.Z, vector4Value.Y, vector4Value.X );
}

FRotator UPPKLibraryTools::RotatorOrderRight( const FRotator &rotatorValue ) {
	return FRotator( rotatorValue.Roll, rotatorValue.Pitch, rotatorValue.Yaw );
}

FVector UPPKLibraryTools::VectorOrderRight( const FVector &vectorValue ) {
	return FVector( vectorValue.Z, vectorValue.X, vectorValue.Y );
}

FVector4 UPPKLibraryTools::Vector4OrderRight( const FVector4 &vector4Value ) {
	return FVector4( vector4Value.W, vector4Value.X, vector4Value.Y, vector4Value.Z );
}

FRotator UPPKLibraryTools::RotatorOrderLeft( const FRotator &rotatorValue ) {
	return FRotator( rotatorValue.Yaw, rotatorValue.Roll, rotatorValue.Pitch );
}

FVector UPPKLibraryTools::VectorOrderLeft( const FVector &vectorValue ) {
	return FVector( vectorValue.Y, vectorValue.Z, vectorValue.X );
}

FVector4 UPPKLibraryTools::Vector4OrderLeft( const FVector4 &vector4Value ) {
	return FVector4( vector4Value.Y, vector4Value.Z, vector4Value.W, vector4Value.X );
}

bool UPPKLibraryTools::GetConfigBool( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

int32 UPPKLibraryTools::GetConfigInt( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

float UPPKLibraryTools::GetConfigFloat( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

FVector UPPKLibraryTools::GetConfigVector( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

FRotator UPPKLibraryTools::GetConfigRotator( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

FLinearColor UPPKLibraryTools::GetConfigColor( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

FString UPPKLibraryTools::GetConfigString( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

FVector2D UPPKLibraryTools::GetConfigVector2D( const FString sectionName, const FString variableName, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigBool( const FString sectionName, const FString variableName, const bool value, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigInt( const FString sectionName, const FString variableName, const int32 value, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigFloat( const FString sectionName, const FString variableName, const float value, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigVector( const FString sectionName, const FString variableName, const FVector value, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigRotator( const FString sectionName, const FString variableName, const FRotator value, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigColor( const FString sectionName, const FString variableName, const FLinearColor value, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigString( const FString sectionName, const FString variableName, const FString value, const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigVector2D( const FString sectionName, const FString variableName, const FVector2D value, const EIniFilesList iniFile ) {
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