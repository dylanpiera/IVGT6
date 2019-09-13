

#include "ToolbarGraphics.h"
#include "SlateOptMacros.h"
#include "Engine.h"

//Already given upon creation, needs to surround Construct
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void ToolbarGraphics::Construct(const FArguments& InArgs)
{
	// Retrieve arguments
	_ownerHUD = InArgs._OwnerHUDArg;
	_dataHolder = InArgs._DataHolderArgs;

	// Set style (fonts, images, icons...)
	StyleSettings();

	// Close toolbar view options panel
	IsOpenToolbarViewPanel = false;
	// Interface
	ChildSlot
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
	[
		// Toolbar
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Center)
		.Padding(FMargin(0, 0, 0, 10))
		[
			// Toolbar View Options Panel
			SNew(SBox)
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Visibility(this, &ToolbarGraphics::GetToolbarViewVisibility)
			[
				// Background Image
				SNew(SBorder)
				.BorderBackgroundColor(FLinearColor(56, 56, 56, 0.7f))
				.BorderImage(new FSlateDynamicImageBrush(FName(*ImagePaths[BackgroundImagePath]), FVector2D(10, 10)))
				[
					SNew(SHorizontalBox)
					// Roads Section
					+ SHorizontalBox::Slot()
					.Padding(FMargin(10, 10))
					[
						// Road Options
						SNew(SUniformGridPanel)
						.SlotPadding(FMargin(5.0f))
						.Visibility(this, &ToolbarGraphics::GetSectionVisibility, RoadsSection)
						// Road 1
						+ SUniformGridPanel::Slot(0, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Road1_IconPath]), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SAssignNew(RoughRoadButton, SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectRoad, RoughRoad)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, RoughRoad)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
					]
					// Buildings Section
					+ SHorizontalBox::Slot()
					.Padding(FMargin(10, 10))
					[
						// Building Options
						SNew(SUniformGridPanel)
						.SlotPadding(FMargin(5.0f))
						.Visibility(this, &ToolbarGraphics::GetSectionVisibility, BuildingsSection)
						// Building 1
						+ SUniformGridPanel::Slot(0, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Building1_IconPath]), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SAssignNew(EnergyButton, SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectBuilding, EnergyBuilding)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, EnergyBuilding)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
						// Building 2
						+ SUniformGridPanel::Slot(1, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Building3_IconPath]), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SAssignNew(MineralButton, SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectBuilding, MineralsBuilding)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, MineralsBuilding)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
						// Building 3
						+ SUniformGridPanel::Slot(2, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Building2_IconPath]), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SAssignNew(HouseButton, SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectBuilding, HouseBuilding)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, HouseBuilding)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
						// Building 4
							+ SUniformGridPanel::Slot(3, 0)
							[
								SNew(SVerticalBox)
								+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
							[
								SNew(SImage)
								.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Building4_IconPath]), FVector2D(100, 100)))
							]
							+ SOverlay::Slot()
							[
								SAssignNew(FoodButton, SButton)
								.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
								.OnClicked(this, &ToolbarGraphics::SelectBuilding, FoodBuilding)
								.DesiredSizeScale(FVector2D(60, 60))
							]
							]
							+ SVerticalBox::Slot()
							.AutoHeight()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, FoodBuilding)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
					]
				]
			]
		]
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Center)
		.AutoHeight()
		.Padding(FMargin(0, 0, 0, 10))
		[
			// Toolbar Sections Panel
			SNew(SBox)
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			[
				SNew(SUniformGridPanel)
				.SlotPadding(FMargin(5.0f))
				// Roads Section
				+ SUniformGridPanel::Slot(0, 0)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SImage)
						.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Road_IconPath]), FVector2D(100, 100)))
					]
					+ SOverlay::Slot()
					[
						SAssignNew(RoadButton, SButton)
						.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0))
						.OnClicked(this, &ToolbarGraphics::ChangeSection, RoadsSection)
					]
				]
				// Buildings Section
				+ SUniformGridPanel::Slot(1, 0)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SImage)
						.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Building_IconPath]), FVector2D(100, 100)))
					]
					+ SOverlay::Slot()
					[
						SAssignNew(BuildingButton, SButton)
						.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0))
						.OnClicked(this, &ToolbarGraphics::ChangeSection, BuildingsSection)
					]
				]
				// Destroy
				+ SUniformGridPanel::Slot(2, 0)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SImage)
						.Image(new FSlateDynamicImageBrush(FName(*ImagePaths[Destroy_IconPath]), FVector2D(100, 100)))
					]
					+ SOverlay::Slot()
					[
						SAssignNew(DestroyButton, SButton)
						.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0))
						.OnClicked(this, &ToolbarGraphics::SelectBuilding, DestroyTool)
					]
				]
			]
		]
	];

	/**
	 * @brief Text for each tooltip of the buttons
	 *
	 */
	RoadButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Roads")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);

	RoughRoadButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Standard Road")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);

	EnergyButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("-100 Minerals + 50 Energy / Contant: -25 Credits")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);

	MineralButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("-50 Minerals -20 Energy / Constant: -10 Credits + 5 Minerals")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);

	HouseButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("-25 Minerals -10 Energy +10 Population")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);

	FoodButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("-20 Minerals -5 Energy / Constant: +15 Food")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);

	BuildingButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Buildings")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);

	DestroyButton->SetToolTip(
		SNew(SToolTip)
		[
			SNew(STextBlock)
			.Text(FText::FromString(TEXT("Destroy")))
			.Font(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Assets/Raleway-Bold.ttf"), 42))
		]
	);
}
//Already given upon creation, needs to go immediately after Construct
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

// Get option title for section
FText ToolbarGraphics::GetOptionTitle(OptionSections OptionIndex) const
{
	FString OptionName = OptionsTitles[OptionIndex];
	return FText::FromString(OptionName);
}

// Select road option
FReply ToolbarGraphics::SelectRoad(OptionSections Index) const
{
	return FReply::Handled();
}

// Select building option
FReply ToolbarGraphics::SelectBuilding(OptionSections Index)
{	
	_dataHolder->SetBuilding(Index);
	
	return FReply::Handled();
}

FReply ToolbarGraphics::HoverBuilding(OptionSections Index)
{
	return FReply::Handled();
}

// Change which section is selected
FReply ToolbarGraphics::ChangeSection(ToolbarSections Index) const
{
	if(CurrentSection == Index && IsOpenToolbarViewPanel) // If section is opened, close it
	{
		IsOpenToolbarViewPanel = false;
	}
	else { // If changing section or no section is open, open new section
		CurrentSection = Index;
		IsOpenToolbarViewPanel = true;
	}

	return FReply::Handled();
}

// Update which section should be visible
EVisibility ToolbarGraphics::GetSectionVisibility(ToolbarSections Index) const
{
	bool SectionVisibility = false;
	if (Index == CurrentSection) { // If section is current section then display, otherwise collapse section options
		SectionVisibility = true;
	}
	
	return SectionVisibility ? EVisibility::Visible : EVisibility::Collapsed;
}

// Get toolbar view options panel visibility
EVisibility ToolbarGraphics::GetToolbarViewVisibility() const
{
	return IsOpenToolbarViewPanel ? EVisibility::Visible : EVisibility::Hidden;
}

// Get section name to be displayed on interface (section names are predefined on header)
FText ToolbarGraphics::GetSectionTitle(ToolbarSections Index) const
{
	FString SectionName = SectionsTitles[Index];
	return FText::FromString(SectionName);
}

// Destroy building/road
FReply ToolbarGraphics::Destroy() const
{
	return FReply::Handled();
}

void ToolbarGraphics::StyleSettings()
{
	// Define text font
	FString ArialFontPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Fonts/Arial.ttf";
	ArialFont = FSlateFontInfo(ArialFontPath, 20);

	FString ProjectDir = FString(FPaths::ProjectContentDir());

	// Toolbar view options panel background image
	ImagePaths.insert(pair<ImageTypes, FString>(BackgroundImagePath, ProjectDir + "Assets/UI/Images/BlackBackground.png"));

	// Sections Icons
	ImagePaths.insert(pair<ImageTypes, FString>(Road_IconPath, ProjectDir + "Assets/UI/Images/Road_Icon.png"));
	ImagePaths.insert(pair<ImageTypes, FString>(Building_IconPath, ProjectDir + "Assets/UI/Images/Building_Icon.png"));
	ImagePaths.insert(pair<ImageTypes, FString>(Destroy_IconPath, ProjectDir + "Assets/UI/Images/Destroy_Icon.png"));

	// Options Icons
	ImagePaths.insert(pair<ImageTypes, FString>(Road1_IconPath, ProjectDir + "Assets/UI/Images/Road_Icon_1.png"));
	ImagePaths.insert(pair<ImageTypes, FString>(Building1_IconPath, ProjectDir + "Assets/UI/Images/Building_Icon_1.png"));
	ImagePaths.insert(pair<ImageTypes, FString>(Building2_IconPath, ProjectDir + "Assets/UI/Images/Building_Icon_2.png"));
	ImagePaths.insert(pair<ImageTypes, FString>(Building3_IconPath, ProjectDir + "Assets/UI/Images/Building_Icon_3.png"));
	ImagePaths.insert(pair<ImageTypes, FString>(Building4_IconPath, ProjectDir + "Assets/UI/Images/Building_Icon_4.png"));
}