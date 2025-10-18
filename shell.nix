{
  pkgs ?
    import <nixpkgs> {
      overlays = [
        (final: prev: {
          wb32-dfu-updater = prev.wb32-dfu-updater.overrideAttrs (old: {
            cmakeFlags = (old.cmakeFlags or []) ++ [
            "-DCMAKE_POLICY_VERSION_MINIMUM=3.5"
            ];
          });
        })
      ];
    }
}:
pkgs.mkShell {
  name = "qmk-env";
  buildInputs = [pkgs.qmk];
}
