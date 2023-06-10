from conans import ConanFile

class HephaestusConan(ConanFile):
    ############################################################################
    ## Package info.                                                          ##
    ############################################################################
    
    name = "hephaestus"
    
    description = "..."
    
    url = "https://github.com/TimZoet/Hephaestus"

    ############################################################################
    ## Settings.                                                              ##
    ############################################################################

    python_requires = "pyreq/1.0.0@timzoet/stable"
    
    python_requires_extend = "pyreq.BaseConan"
    
    options = {
        "shared": [True, False]
    }
    
    default_options = {
        "shared": False
    }
    
    ############################################################################
    ## Base methods.                                                          ##
    ############################################################################
    
    def set_version(self):
        base = self.python_requires["pyreq"].module.BaseConan
        base.set_version(self, "modules/hephaestus-gui/hephaestusVersionString.cmake", "HEPHAESTUS_VERSION")
    
    def init(self):
        base = self.python_requires["pyreq"].module.BaseConan
        self.generators = base.generators + self.generators
        self.settings = base.settings + self.settings
        self.options = {**base.options, **self.options}
        self.default_options = {**base.default_options, **self.default_options}
    
    ############################################################################
    ## Building.                                                              ##
    ############################################################################
    
    def export_sources(self):
        self.copy("CMakeLists.txt")
        self.copy("license")
        self.copy("readme.md")
        self.copy("cmake/*")
        self.copy("modules/*")
    
    def config_options(self):
        base = self.python_requires["pyreq"].module.BaseConan
        if self.settings.os == "Windows":
            del self.options.fPIC
    
    def requirements(self):
        base = self.python_requires["pyreq"].module.BaseConan
        base.requirements(self)
        
        self.requires("alexandria/1.0.0@timzoet/stable")
        self.requires("boost/1.80.0")
        self.requires("common/1.0.0@timzoet/stable")
        self.requires("floah/1.0.0@timzoet/stable")
        self.requires("math/1.0.0@timzoet/stable")
        self.requires("nativefiledialog-extended/1.0.0@timzoet/stable")
        self.requires("sol/1.0.0@timzoet/stable")
        
        # Overrides.
        self.requires("zlib/1.2.12")
        
        if self.options.build_tests:
            self.requires("bettertest/1.0.0@timzoet/stable")
    
    def package_info(self):
        self.cpp_info.components["gui"].libs = ["hephaestus-gui"]
        self.cpp_info.components["gui"].requires = ["version", "common::common", "floah::widget", "math::math", "sol::core"]
        
        self.cpp_info.components["plugin-api"].libs = ["hephaestus-plugin-api"]
        self.cpp_info.components["plugin-api"].requires = ["boost::dll"]
        
        self.cpp_info.components["plugin-loader"].libs = ["hephaestus-plugin-loader"]
        self.cpp_info.components["plugin-loader"].requires = ["plugin-api", "boost::dll"]
        
        self.cpp_info.components["settings"].libs = ["hephaestus-settings"]
        self.cpp_info.components["settings"].requires = ["version", "alexandria::alexandria"]
        
        self.cpp_info.components["version"].libs = ["hephaestus-version"]
        self.cpp_info.components["version"].requires = []
    
    def generate(self):
        base = self.python_requires["pyreq"].module.BaseConan
        
        tc = base.generate_toolchain(self)
        
        if self.options.shared:
            tc.variables["HEPHAESTUS_SHARED_LIBS"] = True
        
        tc.generate()
        
        deps = base.generate_deps(self)
        deps.generate()
    
    def configure_cmake(self):
        base = self.python_requires["pyreq"].module.BaseConan
        cmake = base.configure_cmake(self)
        
        if self.options.shared:
            cmake.definitions["HEPHAESTUS_SHARED_LIBS"] = True
        
        return cmake

    def build(self):
        cmake = self.configure_cmake()
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = self.configure_cmake()
        cmake.install()
