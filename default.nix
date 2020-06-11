{  pkgs ? import <nixpkgs> {} }:
pkgs.stdenv.mkDerivation rec {
  pname = "btrfsrm";
  version = "0.0.1";
  name = "${pname}-${version}";
  src = ./.;
  installPhase = ''
    mkdir -p $out/bin
    cp btrfsrm $out/bin
  '';
  buildInputs = [ pkgs.btrfs-progs ];
}
