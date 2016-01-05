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


UPPKLibraryTools::UPPKLibraryTools( const class FObjectInitializer& ObjectInitializer ) {

}

void UPPKLibraryTools::PrintBoolArray( const TArray<bool> BoolArray, const bool SingleString, const FString& Text, const bool NoText,
									   float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( BoolArray.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < BoolArray.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ( BoolArray[i] ? TEXT( "true" ) : TEXT( "false" ) ) );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayBoolToString( BoolArray ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The Bool Array is empty" ) );
	}
#endif
}

void UPPKLibraryTools::PrintByteArray( const TArray<uint8> ByteArray, const bool SingleString, const FString& Text, const bool NoText,
									   float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( ByteArray.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < ByteArray.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + FString::FromInt( ByteArray[i] ) );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayByteToString( ByteArray ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The Byte Array is empty" ) );
	}
#endif
}

void UPPKLibraryTools::PrintIntegerArray( const TArray<int32> IntArray, const bool SingleString, const FString& Text, const bool NoText,
										  float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( IntArray.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < IntArray.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + FString::FromInt( IntArray[i] ) );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayIntegerToString( IntArray ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The Integer Array is empty" ) );
	}
#endif
}

void UPPKLibraryTools::PrintFloatArray( const TArray<float> FloatArray, const bool SingleString, const FString& Text, const bool NoText,
										float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( FloatArray.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < FloatArray.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + FString::SanitizeFloat( FloatArray[i] ) );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayFloatToString( FloatArray ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The Float Array is empty" ) );
	}
#endif
}

void UPPKLibraryTools::PrintVector2DArray( const TArray<FVector2D> Vector2DArray, const bool SingleString, const FString& Text,
										   const bool NoText, float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( Vector2DArray.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < Vector2DArray.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + "( " +
												  FString::SanitizeFloat( Vector2DArray[i].X ) + " , " + 
												  FString::SanitizeFloat( Vector2DArray[i].Y ) + " )" );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayVector2DToString( Vector2DArray ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The FVector2D Array is empty" ) );
	}
#endif
}

void UPPKLibraryTools::PrintVectorArray( const TArray<FVector> VectorArray, const bool SingleString, const FString& Text, const bool NoText,
										 float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( VectorArray.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < VectorArray.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + "( " +
												  FString::SanitizeFloat( VectorArray[i].X ) + " , " + 
												  FString::SanitizeFloat( VectorArray[i].Y ) + " , " + 
												  FString::SanitizeFloat( VectorArray[i].Z ) + " )" );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayVectorToString( VectorArray ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The FVector Array is empty" ) );
	}
#endif
}

void UPPKLibraryTools::PrintVector4Array( const TArray<FVector4> Vector4Array, const bool SingleString, const FString& Text,
										  const bool NoText, float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( Vector4Array.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < Vector4Array.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, Text + "( " +
												  FString::SanitizeFloat( Vector4Array[i].X ) + " , " +
												  FString::SanitizeFloat( Vector4Array[i].Y ) + " , " +
												  FString::SanitizeFloat( Vector4Array[i].Z ) + " , " +
												  FString::SanitizeFloat( Vector4Array[i].W ) + " )" );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayVector4ToString( Vector4Array ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The FVector4 Array is empty" ) );
	}
#endif
}

void UPPKLibraryTools::PrintRotatorArray( const TArray<FRotator> RotatorArray, const bool SingleString, const FString& Text,
										  const bool NoText, float Duration ) {
#if !( UE_BUILD_TEST || UE_BUILD_SHIPPING ) // Do not Print in Shipping or Test builds
	if ( NoText ) { Text == ""; }
	if ( GConfig && Duration < 0 ) { GConfig->GetFloat( TEXT( "Kismet" ), TEXT( "PrintStringDuration" ), Duration, GEngineIni ); }
	if ( RotatorArray.Num() != 0 ) {
		if ( !SingleString ) {
			for ( int32 i = 0; i < RotatorArray.Num(); i++ ) {
				GEngine->AddOnScreenDebugMessage( -1, 10.f, FColor::Green, Text + "( " +
												  FString::SanitizeFloat( RotatorArray[i].Pitch ) + " , " +
												  FString::SanitizeFloat( RotatorArray[i].Roll ) + " , " +
												  FString::SanitizeFloat( RotatorArray[i].Yaw ) + " )" );
			}
		} else {
			GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Green, Text + ArrayRotatorToString( RotatorArray ) );
		}
	} else {
		GEngine->AddOnScreenDebugMessage( -1, Duration, FColor::Yellow, TEXT( "The FRotator Array is empty" ) );
	}
#endif
}



FString UPPKLibraryTools::ArrayBoolToString( const TArray<bool> BoolArray ) {
	FString tempString = TEXT( "Empty" );
	if ( BoolArray.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < BoolArray.Num(); i++ ) {
			if ( i == 0 ) { tempString = tempString + ( BoolArray[i] ? TEXT( "true" ) : TEXT( "false" ) ); 
			} else { tempString = tempString + ", " + ( BoolArray[i] ? TEXT( "true" ) : TEXT( "false" ) ); }
		}
		tempString = tempString + " }";
	}
	return tempString;
}


FString UPPKLibraryTools::ArrayByteToString( const TArray<uint8> ByteArray ) {
	FString tempString = TEXT( "Empty" );
	if ( ByteArray.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < ByteArray.Num(); i++ ) {
			if ( i == 0 ) { tempString = tempString + FString::FromInt( ByteArray[i] ); 
			} else { tempString = tempString + ", " + FString::FromInt( ByteArray[i] ); }
		}
		tempString = tempString + " }";
	}
	return tempString;
}


FString UPPKLibraryTools::ArrayIntegerToString( const TArray<int32> IntArray ) {
	FString tempString = TEXT( "Empty" );
	if ( IntArray.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < IntArray.Num(); i++ ) {
			if ( i == 0 ) { tempString = tempString + FString::FromInt( IntArray[i] ); 
			} else { tempString = tempString + ", " + FString::FromInt( IntArray[i] ); }
		}
		tempString = tempString + " }";
	}
	return tempString;
}


FString UPPKLibraryTools::ArrayFloatToString( const TArray<float> FloatArray ) {
	FString tempString = TEXT( "Empty" );
	if ( FloatArray.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < FloatArray.Num(); i++ ) {
			if ( i == 0 ) { tempString = tempString + FString::SanitizeFloat( FloatArray[i] ); 
			} else { tempString = tempString + ", " + FString::SanitizeFloat( FloatArray[i] ); }
		}
		tempString = tempString + " }";
	}
	return tempString;
}


FString UPPKLibraryTools::ArrayVector2DToString( const TArray<FVector2D> Vector2DArray ) {
	FString tempString = TEXT( "Empty" );
	if ( Vector2DArray.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < Vector2DArray.Num(); i++ ) {
			if ( i == 0 ) { 
				tempString = tempString + "( " +
				FString::SanitizeFloat( Vector2DArray[i].X ) + " , " +
				FString::SanitizeFloat( Vector2DArray[i].Y ) + " )";
			} else { 
				tempString = tempString + ", " + "( " +
				FString::SanitizeFloat( Vector2DArray[i].X ) + " , " +
				FString::SanitizeFloat( Vector2DArray[i].Y ) + " )";
			}
		}
		tempString = tempString + " }";
	}
	return tempString;
}


FString UPPKLibraryTools::ArrayVectorToString( const TArray<FVector> VectorArray ) {
	FString tempString = TEXT( "Empty" );
	if ( VectorArray.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < VectorArray.Num(); i++ ) {
			if ( i == 0 ) { 
				tempString = tempString + "( " +
					FString::SanitizeFloat( VectorArray[i].X ) + " , " +
					FString::SanitizeFloat( VectorArray[i].Y ) + " , " +
					FString::SanitizeFloat( VectorArray[i].Z ) + " )";
			} else { 
				tempString = tempString + ", " + "( " +
					FString::SanitizeFloat( VectorArray[i].X ) + " , " +
					FString::SanitizeFloat( VectorArray[i].Y ) + " , " +
					FString::SanitizeFloat( VectorArray[i].Z ) + " )"; }
		}
		tempString = tempString + " }";
	}
	return tempString;
}


FString UPPKLibraryTools::ArrayVector4ToString( const TArray<FVector4> Vector4Array ) {
	FString tempString = TEXT( "Empty" );
	if ( Vector4Array.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < Vector4Array.Num(); i++ ) {
			if ( i == 0 ) { 
				tempString = tempString + "( " +
					FString::SanitizeFloat( Vector4Array[i].X ) + " , " +
					FString::SanitizeFloat( Vector4Array[i].Y ) + " , " +
					FString::SanitizeFloat( Vector4Array[i].Z ) + " , " +
					FString::SanitizeFloat( Vector4Array[i].W ) + " )";
			} else { 
				tempString = tempString + ", " + "( " +
					FString::SanitizeFloat( Vector4Array[i].X ) + " , " +
					FString::SanitizeFloat( Vector4Array[i].Y ) + " , " +
					FString::SanitizeFloat( Vector4Array[i].Z ) + " , " +
					FString::SanitizeFloat( Vector4Array[i].W ) + " )"; }
		}
		tempString = tempString + " }";
	}
	return tempString;
}


FString UPPKLibraryTools::ArrayRotatorToString( const TArray<FRotator> RotatorArray ) {
	FString tempString = TEXT( "Empty" );
	if ( RotatorArray.Num() != 0 ) {
		tempString = "{ ";
		for ( int32 i = 0; i < RotatorArray.Num(); i++ ) {
			if ( i == 0 ) { 
				tempString = tempString + "( " +
					FString::SanitizeFloat( RotatorArray[i].Pitch ) + " , " +
					FString::SanitizeFloat( RotatorArray[i].Roll ) + " , " +
					FString::SanitizeFloat( RotatorArray[i].Yaw ) + " )";
			} else { 
				tempString = tempString + ", " + "( " +
					FString::SanitizeFloat( RotatorArray[i].Pitch ) + " , " +
					FString::SanitizeFloat( RotatorArray[i].Roll ) + " , " +
					FString::SanitizeFloat( RotatorArray[i].Yaw ) + " )"; }
		}
		tempString = tempString + " }";
	}
	return tempString;
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

void UPPKLibraryTools::SetConfigBool( const FString sectionName, const FString variableName, const bool value, 
									  const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigInt( const FString sectionName, const FString variableName, const int32 value, 
									 const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigFloat( const FString sectionName, const FString variableName, const float value, 
									   const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigVector( const FString sectionName, const FString variableName, const FVector value, 
										const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigRotator( const FString sectionName, const FString variableName, const FRotator value, 
										 const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigColor( const FString sectionName, const FString variableName, const FLinearColor value, 
									   const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigString( const FString sectionName, const FString variableName, const FString value, 
										const EIniFilesList iniFile ) {
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

void UPPKLibraryTools::SetConfigVector2D( const FString sectionName, const FString variableName, const FVector2D value, 
										  const EIniFilesList iniFile ) {
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