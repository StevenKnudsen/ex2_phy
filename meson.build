project('ex2_phy', 'c', 'cpp',
    license: 'proprietary',
    version: '1.0.0',
    default_options : [
#        'c_std=c11',
#        'cpp_std=c++11',
        'buildtype=release',
        'warning_level=3',
#        'buildtype=debug',
#        'werror=true',
        ],
    )

cpp = meson.get_compiler('cpp')

home = run_command('sh', '-c', 'echo $HOME', check: true)
HOME_DIR = home.stdout().strip()
message('home = ' + HOME_DIR)

prj_dir = run_command('sh', '-c', 'echo $PWD', check: true)
PRJ_DIR = prj_dir.stdout().strip()
message('prj_dir = ' + PRJ_DIR)

core_source_files = [
    PRJ_DIR / 'uhf/src/radio.c',
]

incdir = include_directories(
    'sband/include',
    'uhf/include'
)

install_headers('uhf/include/radio.h', subdir : 'ex2_phy/uhf') # -> include/uhf/radio.h

gtest_dep = dependency('gtest_main', required: false)

if not gtest_dep.found()
    foreach incdir: ['/usr/include/gtest', '/usr/local/include/gtest']
        if cpp.has_header('gtest.h', args: '-I' + incdir)
            gtest_inc = include_directories(incdir)
            break
        endif
    endforeach
    
    gtest_dep = declare_dependency(
        dependencies: [cpp.find_library('gtest'),cpp.find_library('gtest_main')],
        include_directories: gtest_inc,
        )
endif

if not gtest_dep.found()
    error('unable to find gtest dependency')
endif

#thread_dep = dependency('threads')
if gtest_dep.found()
    subdir('sband/unit_tests')
    subdir('uhf/unit_tests')
endif

#subdir('sband/doc')
#subdir('uhf/doc')
