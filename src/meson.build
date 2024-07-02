melodia_launcher_sources = [
  'main.c',
  'app/window/melodia_launcher-window.c',
  'app/melodia_launcher-application.c',
  'features/stack_manager/stack_manager.c',
  'features/dashboard/dashboard.c',
]

melodia_launcher_deps = [
  dependency('gtk4'),
]

gnome = import('gnome')

melodia_launcher_sources += gnome.compile_resources('melodia_launcher-resources',
  'melodia_launcher.gresource.xml',
  c_name: 'melodia_launcher'
)

executable('melodia-launcher', melodia_launcher_sources,
  dependencies: melodia_launcher_deps,
  install: true,
)
