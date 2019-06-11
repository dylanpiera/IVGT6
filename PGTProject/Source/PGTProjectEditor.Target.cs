using UnrealBuildTool;
using System.Collections.Generic;

public class PGTProjectEditorTarget : TargetRules
{
	public PGTProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "PGTProject" } );
	}
}
