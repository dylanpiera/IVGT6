version: 0.6f
alphabet:
name: "TileAlphabet"
position: (-28,-62)

module:
name: "DifficultySketch"
alphabet: "TileAlphabet"
position: (-102,60)
type: Grammar
match: None
grammar: true
showMembers: true

module:
name: "SplitTiles"
alphabet: "TileAlphabet"
position: (10,60)
type: Recipe
match: None
inputs: "DifficultySketch"
recipe: true
showMembers: true

module:
name: "Expand"
alphabet: "TileAlphabet"
position: (102,62)
type: Recipe
match: None
inputs: "SplitTiles"
grammar: true
executionType: LSystem
recipe: true
showMembers: true

option: Width 8
option: Height 8
option: Tile "undefined"
