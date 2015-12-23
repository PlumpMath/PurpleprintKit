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

UPPKLibraryMath::UPPKLibraryMath( const class FObjectInitializer& ObjectInitializer ) {

}

std::random_device rd;
unsigned gseed = std::chrono::system_clock::now().time_since_epoch().count();

float UPPKLibraryMath::AreaUnitsConverterSimple( const float UnitValue, const EAreaUnitsList UnitFrom, const EAreaUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitTo );
}

void UPPKLibraryMath::AreaUnitsConverterAdvanced( const float UnitValue, const EAreaUnitsList UnitFrom, const EAreaUnitsList UnitToValueA, const EAreaUnitsList UnitToValueB,
												  const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::AreaUnitsConverterComplete( const float UnitValue, const EAreaUnitsList UnitFrom, const bool bTruncate, FAreaUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.USKilometre = ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSKilometre );

	} else {
		UnitList.USKilometre = FMath::TruncToFloat( ( UnitValue / GetAreaUnitValue( UnitFrom ) ) * GetAreaUnitValue( EAreaUnitsList::AUSKilometre ) );
	}
}

float UPPKLibraryMath::DTRUnitsConverterSimple( const float UnitValue, const EDTRUnitsList UnitFrom, const EDTRUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitTo );
}

void UPPKLibraryMath::DTRUnitsConverterAdvanced( const float UnitValue, const EDTRUnitsList UnitFrom, const EDTRUnitsList UnitToValueA, const EDTRUnitsList UnitToValueB,
												  const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::DTRUnitsConverterComplete( const float UnitValue, const EDTRUnitsList UnitFrom, const bool bTruncate, FDTRUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UBitPS = ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUBitPS );

	} else {
		UnitList.UBitPS = FMath::TruncToFloat( ( UnitValue / GetDTRUnitValue( UnitFrom ) ) * GetDTRUnitValue( EDTRUnitsList::DTRUBitPS ) );
	}
}

float UPPKLibraryMath::DSUnitsConverterSimple( const float UnitValue, const EDSUnitsList UnitFrom, const EDSUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitTo );
}

void UPPKLibraryMath::DSUnitsConverterAdvanced( const float UnitValue, const EDSUnitsList UnitFrom, const EDSUnitsList UnitToValueA, const EDSUnitsList UnitToValueB,
												 const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::DSUnitsConverterComplete( const float UnitValue, const EDSUnitsList UnitFrom, const bool bTruncate, FDSUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UBit = ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUBit );

	} else {
		UnitList.UBit = FMath::TruncToFloat( ( UnitValue / GetDSUnitValue( UnitFrom ) ) * GetDSUnitValue( EDSUnitsList::DSUBit ) );
	}
}

float UPPKLibraryMath::FrequencyUnitsConverterSimple( const float UnitValue, const EFrequencyUnitsList UnitFrom, const EFrequencyUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitTo );
}

void UPPKLibraryMath::FrequencyUnitsConverterAdvanced( const float UnitValue, const EFrequencyUnitsList UnitFrom, const EFrequencyUnitsList UnitToValueA, const EFrequencyUnitsList UnitToValueB,
												 const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::FrequencyUnitsConverterComplete( const float UnitValue, const EFrequencyUnitsList UnitFrom, const bool bTruncate, FFrequencyUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UHertz = ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUHertz );

	} else {
		UnitList.UHertz = FMath::TruncToFloat( ( UnitValue / GetFrequencyUnitValue( UnitFrom ) ) * GetFrequencyUnitValue( EFrequencyUnitsList::FUHertz ) );
	}
}

float UPPKLibraryMath::LenghtUnitsConverterSimple( const float UnitValue, const ELenghtUnitsList UnitFrom, const ELenghtUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitTo );
}

void UPPKLibraryMath::LenghtUnitsConverterAdvanced( const float UnitValue, const ELenghtUnitsList UnitFrom, const ELenghtUnitsList UnitToValueA, const ELenghtUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::LenghtUnitsConverterComplete( const float UnitValue, const ELenghtUnitsList UnitFrom, const bool bTruncate, FLenghtUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UKilometre = ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUKilometre );

	} else {
		UnitList.UKilometre = FMath::TruncToFloat( ( UnitValue / GetLenghtUnitValue( UnitFrom ) ) * GetLenghtUnitValue( ELenghtUnitsList::LUKilometre ) );
	}
}

float UPPKLibraryMath::MassUnitsConverterSimple( const float UnitValue, const EMassUnitsList UnitFrom, const EMassUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitTo );
}

void UPPKLibraryMath::MassUnitsConverterAdvanced( const float UnitValue, const EMassUnitsList UnitFrom, const EMassUnitsList UnitToValueA, const EMassUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::MassUnitsConverterComplete( const float UnitValue, const EMassUnitsList UnitFrom, const bool bTruncate, FMassUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UTonne = ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUTonne );

	} else {
		UnitList.UTonne = FMath::TruncToFloat( ( UnitValue / GetMassUnitValue( UnitFrom ) ) * GetMassUnitValue( EMassUnitsList::MUTonne ) );
	}
}

float UPPKLibraryMath::PAUnitsConverterSimple( const float UnitValue, const EPAUnitsList UnitFrom, const EPAUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitTo );
}

void UPPKLibraryMath::PAUnitsConverterAdvanced( const float UnitValue, const EPAUnitsList UnitFrom, const EPAUnitsList UnitToValueA, const EPAUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::PAUnitsConverterComplete( const float UnitValue, const EPAUnitsList UnitFrom, const bool bTruncate, FPAUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UAngularMil = ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUAngularMil );

	} else {
		UnitList.UAngularMil = FMath::TruncToFloat( ( UnitValue / GetPAUnitValue( UnitFrom ) ) * GetPAUnitValue( EPAUnitsList::PAUAngularMil ) );
	}
}

float UPPKLibraryMath::SpeedUnitsConverterSimple( const float UnitValue, const ESpeedUnitsList UnitFrom, const ESpeedUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitTo );
}

void UPPKLibraryMath::SpeedUnitsConverterAdvanced( const float UnitValue, const ESpeedUnitsList UnitFrom, const ESpeedUnitsList UnitToValueA, const ESpeedUnitsList UnitToValueB,
													   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::SpeedUnitsConverterComplete( const float UnitValue, const ESpeedUnitsList UnitFrom, const bool bTruncate, FSpeedUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UMilesPH = ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUMilesPH );

	} else {
		UnitList.UMilesPH = FMath::TruncToFloat( ( UnitValue / GetSpeedUnitValue( UnitFrom ) ) * GetSpeedUnitValue( ESpeedUnitsList::SUMilesPH ) );
	}
}

float UPPKLibraryMath::TempUnitsConverterSimple( const float UnitValue, const ETempUnitsList UnitFrom, const ETempUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitTo );
}

void UPPKLibraryMath::TempUnitsConverterAdvanced( const float UnitValue, const ETempUnitsList UnitFrom, const ETempUnitsList UnitToValueA, const ETempUnitsList UnitToValueB,
												   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::TempUnitsConverterComplete( const float UnitValue, const ETempUnitsList UnitFrom, const bool bTruncate, FTempUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UCelsius = ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUCelsius );

	} else {
		UnitList.UCelsius = FMath::TruncToFloat( ( UnitValue / GetTempUnitValue( UnitFrom ) ) * GetTempUnitValue( ETempUnitsList::TUCelsius ) );
	}
}

float UPPKLibraryMath::TimeUnitsConverterSimple( const float UnitValue, const ETimeUnitsList UnitFrom, const ETimeUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitTo ) );
	}
		return ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitTo );
}

void UPPKLibraryMath::TimeUnitsConverterAdvanced( const float UnitValue, const ETimeUnitsList UnitFrom, const ETimeUnitsList UnitToValueA, const ETimeUnitsList UnitToValueB, 
												  const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::TimeUnitsConverterComplete( const float UnitValue, const ETimeUnitsList UnitFrom, const bool bTruncate, FTimeUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UNanosecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUNanosecond );
		UnitList.UMicrosecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMicrosecond );
		UnitList.UMillisecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMillisecond );
		UnitList.USecond = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUSecond );
		UnitList.UMinute = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMinute );
		UnitList.UHour = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUHour );
		UnitList.UDay = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDay );
		UnitList.UWeek = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUWeek );
		UnitList.UMonth = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMonth );
		UnitList.UYear = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUYear );
		UnitList.UDecade = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDecade );
		UnitList.UCentury = ( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUCentury );
	} else {
		UnitList.UNanosecond = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUNanosecond ));
		UnitList.UMicrosecond = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMicrosecond ));
		UnitList.UMillisecond = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMillisecond ));
		UnitList.USecond = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUSecond ));
		UnitList.UMinute = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMinute ));
		UnitList.UHour = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUHour ));
		UnitList.UDay = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDay ));
		UnitList.UWeek = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUWeek ));
		UnitList.UMonth = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUMonth ));
		UnitList.UYear = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUYear ));
		UnitList.UDecade = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUDecade ));
		UnitList.UCentury = FMath::TruncToFloat(( UnitValue / GetTimeUnitValue( UnitFrom ) ) * GetTimeUnitValue( ETimeUnitsList::TUCentury ));
	}
}

float UPPKLibraryMath::VolUnitsConverterSimple( const float UnitValue, const EVolUnitsList UnitFrom, const EVolUnitsList UnitTo, const bool bTruncate ) {
	if ( bTruncate ) {
		return FMath::TruncToFloat( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitTo ) );
	}
	return ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitTo );
}

void UPPKLibraryMath::VolUnitsConverterAdvanced( const float UnitValue, const EVolUnitsList UnitFrom, const EVolUnitsList UnitToValueA, const EVolUnitsList UnitToValueB,
												   const bool bTruncateA, const bool bTruncateB, float& UnitValueOriginal, float& UnitValueATo, float& UnitValueBTo ) {
	UnitValueOriginal = UnitValue;
	if ( !bTruncateA ) {
		UnitValueATo = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueA );
	} else {
		UnitValueATo = FMath::TruncToFloat( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueA ) );
	}

	if ( !bTruncateB ) {
		UnitValueBTo = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueB );
	} else {
		UnitValueBTo = FMath::TruncToFloat( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( UnitToValueB ) );
	}
}

void UPPKLibraryMath::VolUnitsConverterComplete( const float UnitValue, const EVolUnitsList UnitFrom, const bool bTruncate, FVolUnitsStruct& UnitList ) {
	if ( !bTruncate ) {
		UnitList.UUSLiquidGallon = ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidGallon );

	} else {
		UnitList.UUSLiquidGallon = FMath::TruncToFloat( ( UnitValue / GetVolUnitValue( UnitFrom ) ) * GetVolUnitValue( EVolUnitsList::VUUSLiquidGallon ) );
	}
}

float UPPKLibraryMath::GetAreaUnitValue( const EAreaUnitsList AreaUnit ) {
	switch ( AreaUnit ) {
		case EAreaUnitsList::AUSKilometre:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetDTRUnitValue( const EDTRUnitsList DTRUnit ) {
	switch ( DTRUnit ) {
		case EDTRUnitsList::DTRUBitPS:
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetDSUnitValue( const EDSUnitsList DSUnit ) {
	switch ( DSUnit ) {
		case EDSUnitsList::DSUBit:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetFrequencyUnitValue( const EFrequencyUnitsList FrequencyUnit ) {
	switch ( FrequencyUnit ) {
		case EFrequencyUnitsList::FUHertz:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetLenghtUnitValue( const ELenghtUnitsList LenghtUnit ) {
	switch ( LenghtUnit ) {
		case ELenghtUnitsList::LUKilometre:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetMassUnitValue( const EMassUnitsList MassUnit ) {
	switch ( MassUnit ) {
		case EMassUnitsList::MUTonne:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetPAUnitValue( const EPAUnitsList PAUnit ) {
	switch ( PAUnit ) {
		case EPAUnitsList::PAUAngularMil:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetSpeedUnitValue( const ESpeedUnitsList SpeedUnit ) {
	switch ( SpeedUnit ) {
		case ESpeedUnitsList::SUMilesPH:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetTempUnitValue( const ETempUnitsList TempUnit ) {
	switch ( TempUnit ) {
		case ETempUnitsList::TUCelsius:
			return 1.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetTimeUnitValue( const ETimeUnitsList TimeUnit ) {
	switch ( TimeUnit ) {
		case ETimeUnitsList::TUNanosecond:
			return 1.f * 60.f * 60.f * 1000.f * 1000.f * 1000.f;
			break;
		case ETimeUnitsList::TUMicrosecond:
			return 1.f * 60.f * 60.f * 1000.f * 1000.f;
			break;
		case ETimeUnitsList::TUMillisecond:
			return 1.f * 60.f * 60.f * 1000.f;
			break;
		case ETimeUnitsList::TUSecond:
			return 1.f * 60.f * 60.f;
			break;
		case ETimeUnitsList::TUMinute:
			return 1.f * 60.f;
			break;
		case ETimeUnitsList::TUHour:
			return 1.f; //Base
			break;
		case ETimeUnitsList::TUDay:
			return 1.f / 24.f;
			break;
		case ETimeUnitsList::TUWeek:
			return ( 1.f / 24.f ) / 7.f;
			break;
		case ETimeUnitsList::TUMonth:
			return ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f;
			break;
		case ETimeUnitsList::TUYear:
			return ( ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f ) / 12.f;
			break;
		case ETimeUnitsList::TUDecade:
			return ( ( ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f ) / 12.f ) / 10.f;
			break;
		case ETimeUnitsList::TUCentury:
			return ( ( ( ( ( 1.f / 24.f ) / 7.f ) / 4.34821429f ) / 12.f ) / 10.f ) / 10.f;
			break;
	}
	return 1.f;
}

float UPPKLibraryMath::GetVolUnitValue( const EVolUnitsList VolUnit ) {
	switch ( VolUnit ) {
		case EVolUnitsList::VUUSLiquidGallon:
			break;
	}
	return 1.f;
}

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
