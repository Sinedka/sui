{
  description = "AniParser Electron application";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    let
        forEachSystem = fn:
        nixpkgs.lib.genAttrs
          nixpkgs.lib.platforms.linux
            (system: fn system nixpkgs.legacyPackages.${system});
    in
    {
      devShells = forEachSystem (system: pkgs: rec {
        default = pkgs.mkShell {
          buildInputs = with pkgs; [
            cmake
            gdb
          ];

          shellHook = ''
          '';
        };
      });
    };
}
