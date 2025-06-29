from obsact_to_dart_transpiler import ObsActToDartTranspiler

def main():
  transpiler = ObsActToDartTranspiler()

  paths = [
    # (input, output),
    ("obs_act/1.obs_act", "dart/output.dart"),
    ("obs_act/2.obs_act", "dart/output.dart"),
    ("obs_act/3.obs_act", "dart/output.dart"),
    ("obs_act/4.obs_act", "dart/output.dart"),
    ("obs_act/5.obs_act", "dart/output.dart"),
    ("obs_act/6.obs_act", "dart/output.dart"),
    ("obs_act/7.obs_act", "dart/output.dart"),
    ("obs_act/8.obs_act", "dart/output.dart"),
    ("obs_act/9.obs_act", "dart/output.dart"),
    ("obs_act/10.obs_act", "dart/output.dart"),
    ("obs_act/11.obs_act", "dart/output.dart"),
    ("obs_act/12.obs_act", "dart/output.dart"),
    ("obs_act/13.obs_act", "dart/output.dart"),
    ("obs_act/14.obs_act", "dart/output.dart"),
    ("obs_act/15.obs_act", "dart/output.dart"),
  ]

  provided_examples = [ # Most had to be modified because they contained errors
    ("obs_act/provided_examples/ex1.obs_act", "dart/output.dart"),
    ("obs_act/provided_examples/ex2.obs_act", "dart/output.dart"),
    ("obs_act/provided_examples/ex3.obs_act", "dart/output.dart"),
    ("obs_act/provided_examples/ex5.obs_act", "dart/output.dart"),
    ("obs_act/provided_examples/ex6.obs_act", "dart/output.dart"),
    ("obs_act/provided_examples/ex7.obs_act", "dart/output.dart"),
    ("obs_act/provided_examples/ex8.obs_act", "dart/output.dart"),
  ]

  for source_path, destination_path in paths:
    transpiler.export_file(source_path, destination_path)
    print(f"Transpiled {source_path} to {destination_path}")

if __name__ == "__main__":
  main()
