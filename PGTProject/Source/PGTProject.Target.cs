using UnrealBuildTool;
using System.Collections.Generic;

public class PGTProjectTarget : TargetRules
{
	public PGTProjectTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "PGTProject" } );
	}
}
