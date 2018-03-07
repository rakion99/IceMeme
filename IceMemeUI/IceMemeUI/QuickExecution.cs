using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IceMemeUI
{
    class QuickExecution
    {
        public static string printluac =
            @"getglobal print
            pushstring You Clclicked PrintLuaC Button :D!
            pcall 1 0 0
            emptystack";

        public static string printlua =
            @"print'You Clclicked PrintLua Button :)'";

        public static string luacday =
            @"getglobal game
            getfield -1 GetService
            pushvalue -2
            pushstring Lighting
            pcall 2 1 0
            pushstring 12:00:00
            setfield -2 TimeOfDay
            emptystack";

        public static string luacnight =
            @"getglobal game
            getfield -1 GetService
            pushvalue -2
            pushstring Lighting
            pcall 2 1 0
            pushstring 00:00:00
            setfield -2 TimeOfDay
            emptystack";

        public static string luacilluminati =
            @"getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Humanoid
            pushnumber 3.5
            setfield -2 HipHeight
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Left Arm
            getfield -1 Destroy
            pushvalue -2
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Right Arm
            getfield -1 Destroy
            pushvalue -2
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Right Leg
            pushnumber 1
            setfield -2 Transparency
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Left Leg
            pushnumber 1
            setfield -2 Transparency
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Head
            pushnumber 1
            setfield -2 Transparency
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Head
            getfield -1 face
            pushnumber 1
            setfield -2 Transparency
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Torso
            getglobal Instance
            getfield -1 new
            pushstring ParticleEmitter
            pushvalue -4
            pcall 2 1 0
            pushstring rbxassetid://362575925
            setfield -2 Texture
            pushnumber 100
            setfield -2 VelocitySpread
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Torso
            getglobal Instance
            getfield -1 new
            pushstring SpecialMesh
            pushvalue -4
            pcall 2 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Torso
            getfield -1 Mesh
            pushstring rbxassetid://438530093
            setfield -2 MeshId
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Torso
            getfield -1 Mesh
            pushstring rbxassetid://438530120
            setfield -2 TextureId
            pcall 1 0 0
            settop 0
            getglobal game
            getfield -1 Lighting
            getglobal Instance
            getfield -1 new
            pushstring Sky
            pushvalue -4
            pcall 2 1 0
            pushstring wow
            setfield -2 Name
            pushstring rbxassetid://259226828
            setfield -2 SkyboxBk
            pushstring rbxassetid://259226828
            setfield -2 SkyboxDn
            pushstring rbxassetid://259226828
            setfield -2 SkyboxFt
            pushstring rbxassetid://259226828
            setfield -2 SkyboxLf
            pushstring rbxassetid://259226828
            setfield -2 SkyboxRt
            pushstring rbxassetid://259226828
            setfield -2 SkyboxUp
            settop 0
            getglobal workspace
            getglobal Instance
            getfield -1 new
            pushstring Sound
            pushvalue -4
            pcall 2 1 0
            pushstring rbxassetid://512338922
            setfield -2 SoundId
            pushstring meme
            setfield -2 Name
            pushnumber 1
            setfield -2 Volume
            getfield -1 Play
            pushvalue -2
            pcall 1 0 0
            settop 0";

        public static string luacdkit =
            @"getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getglobal Instance
            getfield -1 new
            pushstring ForceField
            pushvalue -4
            pcall 2 0 0
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Torso
            getglobal Instance
            getfield -1 new
            pushstring Sparkles
            pushvalue -4
            pcall 2 0 0
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Torso
            getglobal Instance
            getfield -1 new
            pushstring Smoke
            pushvalue -4
            pcall 2 0 0
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Torso
            pushstring Brick
            setfield -2 Material
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Right Arm
            pushstring Brick
            setfield -2 Material
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Left Arm
            pushstring Brick
            setfield -2 Material
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Right Leg
            pushstring Brick
            setfield -2 Material
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Left Leg
            pushstring Brick
            setfield -2 Material
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Character
            getfield -1 Humanoid
            pushnumber 200
            setfield -2 WalkSpeed
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Backpack
            getglobal Instance
            getfield -1 new
            pushstring HopperBin
            pushvalue -4
            pcall 2 1 0
            pushnumber 2
            setfield -2 BinType
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Backpack
            getglobal Instance
            getfield -1 new
            pushstring HopperBin
            pushvalue -4
            pcall 2 1 0
            pushnumber 3
            setfield -2 BinType
            emptystack
            getglobal game
            getfield -1 Players
            getfield -1 LocalPlayer
            getfield -1 Backpack
            getglobal Instance
            getfield -1 new
            pushstring HopperBin
            pushvalue -4
            pcall 2 1 0
            pushnumber 4
            setfield -2 BinType
            emptystack";

        public static string luajp =
            @"game.Players.LocalPlayer.Character.Humanoid.JumpPower = 150";

        public static string luaws =
            @"game.Players.LocalPlayer.Character.Humanoid.WalkSpeed = 150";

        public static string luabsod1 =
            @"local a = Instance.new(""Sky"",game.Lighting)
            local b = { ""Bk"", ""Dn"", ""Ft"", ""Lf"", ""Rt"", ""Up"" }
            for _,v in pairs(b) do
            a[""Skybox""..v]=""rbxassetid://111954944""
            end";

        public static string luabsod2 =
            @"local c = Instance.new(""ParticleEmitter"",game.Players.LocalPlayer.Character.Torso)
            c.Texture = ""rbxassetid://79187163""
            c.VelocitySpread = 50";

        public static string luabsod3 =
            @"local d = Instance.new(""Sound"",game.workspace)
            d.SoundId = ""rbxassetid://507839176""
            d.Looped = true
            d:Play()";

        public static string luabsod4 =
            @"local dd = Instance.new(""ParticleEmitter"",game.Players.LocalPlayer.Character.Torso)
            dd.Texture = ""rbxassetid://357822657""
            dd.VelocitySpread = 50";
    }
}
